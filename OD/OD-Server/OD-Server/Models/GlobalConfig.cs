using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Automation.Peers;
using System.Windows.Interop;

namespace OD_Server
{
    class GlobalConfig
    {
        private static GlobalConfig instance;
        public static GlobalConfig Instance
        {
            get
            {
                if(instance == null)
                    instance = new GlobalConfig();
                return instance;
            }
        }
        public GlobalConfig() 
        {
            clientList = new List<Client>();
        }

        public List<Client> clientList;
 
        public string AddClient(string username, byte[] password, string email)
        {
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    return "error:login";
                }
            }
            Client newClient = new Client();
            newClient.Login = username;
            newClient.password = password;
            newClient.email = email;
            clientList.Add(newClient);
            return newClient.firstLoginCode;
        }

        public string FirstLogin(string username, byte[] password, string code, string token)
        {
            int cli = -1;
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    cli = clientList.IndexOf(item);
                }
            }
            if (cli != -1)
            {
                if (clientList[cli].Condition != Client.condition.Disabled)
                {
                    return "error:accactive";
                }
                if (!clientList[cli].CheckPass(password))
                {
                    //skasuj konto
                    clientList.Remove(clientList[cli]);
                    return "error:accremoved";
                }
                else if (clientList[cli].firstLoginCode != code)
                {
                    //skasuj konto
                    clientList.Remove(clientList[cli]);
                    return "error:accremoved";
                }
                else
                {
                    //poprawna autoryzacja
                    clientList[cli].token = token;
                    clientList[cli].Condition = Client.condition.OK;
                    clientList[cli].GenerateSessionID();
                    return clientList[cli].sessionID;
                }
            }
            else
            {
                return "error:nouser";
            }
        }

        public string Login(string username, byte[] password, string token)
        {
            int cli = -1;
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    cli = clientList.IndexOf(item);
                }
            }
            if (cli != -1)
            {
                if (!clientList[cli].CheckPass(password))
                {
                    return "error:wrongpass";
                }
                else
                {
                    DateTime timeN = DateTime.Now;
                    TimeSpan spantime = new TimeSpan(timeN.Ticks);
                    double k = spantime.TotalSeconds;

                    long time = Convert.ToInt64(k - (k%30));

                    if (GenerateTokenCode(time.ToString(), clientList[cli].token) == token ||
                        GenerateTokenCode((time - 30).ToString(), clientList[cli].token) == token)
                    {
                        //poprawna autoryzacja
                        clientList[cli].GenerateSessionID();
                        return clientList[cli].sessionID;
                    }
                    else
                    {
                        return "error:wrongtokencode";
                    }
                }
            }
            else
            {
                return "error:nouser";
            }
        }
        public string Logout(string username, string session)
        {
            int cli = -1;
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    cli = clientList.IndexOf(item);
                }
            }
            if (cli != -1)
            {
                if (clientList[cli].sessionID != session)
                {
                    clientList[cli].sessionID = null;
                    return "error:wrongsession";

                }
                else
                {
                    clientList[cli].sessionID = null;
                    return "oki";
                }
            }
            else
            {
                return "error:nouser";
            }
        }
        public string Message(string username, string session, string txt)
        {
            int cli = -1;
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    cli = clientList.IndexOf(item);
                }
            }
            if (cli != -1)
            {
                if (clientList[cli].sessionID != session)
                {
                    clientList[cli].sessionID = null;
                    return "error:wrongsession";

                }
                else
                {
                    clientList[cli].messages.Add(txt);
                    return "oki";
                }
            }
            else
            {
                return "error:nouser";
            }
        }

        public string GenerateTokenCode(string tim, string tokenID)
        {
            long time = Convert.ToInt64(tim);
            long time2 = time % 30;

            long t = time - time2;
            long k = Convert.ToInt64(tokenID) % t;

            using (MD5 md5Hash = MD5.Create())
            {
                byte[] data = md5Hash.ComputeHash(Encoding.UTF8.GetBytes(k.ToString()));
                StringBuilder sBuilder = new StringBuilder();
                for (int i = 0; i < data.Length; i++)
                {
                    sBuilder.Append(data[i].ToString("x2"));
                }
                string hash = sBuilder.ToString();

                string numb = "";
                for (int i = 0; i < 13; i++)
                {
                    if (hash[i] == 'a')
                        numb += 0;
                    else if (hash[i] == 'b')
                        numb += 1;
                    else if (hash[i] == 'c')
                        numb += 2;
                    else if (hash[i] == 'd')
                        numb += 3;
                    else if (hash[i] == 'e')
                        numb += 4;
                    else if (hash[i] == 'f')
                        numb += 5;
                    else
                    {
                        numb += hash[i];
                    }
                }
                string outp = (Convert.ToInt64(numb) % 99999999).ToString();
                return outp;
            }
        }

    }
}
