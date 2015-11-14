using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Automation.Peers;

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
            Client cli = null;
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    cli = item;
                }
            }
            if (cli != null)
            {
                if (cli.password != password || cli.firstLoginCode != code)
                {
                    //skasuj konto
                    clientList.Remove(cli);
                    return "error:accremoved";
                }
                else
                {
                    //poprawna autoryzacja
                    cli.token = token;
                    cli.Condition = Client.condition.OK;
                    cli.GenerateSessionID();
                    return cli.sessionID;
                }
            }
            else
            {
                return "error:nouser";
            }
        }

        public string Login(string username, byte[] password, string token)
        {
            Client cli = null;
            foreach (Client item in clientList)
            {
                if (item.Login == username)
                {
                    cli = item;
                }
            }
            if (cli != null)
            {
                if (cli.password != password)
                {
                    //skasuj konto
                    clientList.Remove(cli);
                    return "error:accremoved";
                }
                else
                {
                    // sprawdź token f
                    //poprawna autoryzacja
                    cli.GenerateSessionID();
                    return cli.sessionID;
                }
            }
            else
            {
                return "error:nouser";
            }
        }
    }
}
