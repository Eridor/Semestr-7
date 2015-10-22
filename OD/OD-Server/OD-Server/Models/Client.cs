using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OD_Server
{
    class Client
    {
        public bool activated;
        public bool suspended;
        public string Login;
        public string email;
        public string password;

        public int id;

        public Client()
        {
            id = 0;
            activated = false;
            suspended = false;
        }
    }
}
