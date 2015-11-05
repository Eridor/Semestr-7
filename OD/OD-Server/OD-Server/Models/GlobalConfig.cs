using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OD_Server.Models;

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
            clientApps = new List<ClientApp>();
        }

        public List<Client> clientList;
        public List<ClientApp> clientApps;

        public int AddClientApp()
        {
            ClientApp newClient = new ClientApp();
            //newClient.hisKey = System.Text.Encoding.ASCII.GetBytes(publickey);
            newClient.id = clientApps.Count() + 1;
            clientApps.Add(newClient);
            return newClient.id;
        }

    }
}
