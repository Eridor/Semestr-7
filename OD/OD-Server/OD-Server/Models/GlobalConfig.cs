using System;
using System.Collections.Generic;
using System.Linq;
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
                    // sprawdź token f
                    //poprawna autoryzacja
                    clientList[cli].GenerateSessionID();
                    return clientList[cli].sessionID;
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
    }
}
