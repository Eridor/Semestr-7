using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OD_Server
{
    class Client
    {
        public string Login { get; set; }
        public string email { get; set; }
        public byte[] password;
        public string token;
        public string sessionID;
        public string firstLoginCode;

        public condition Condition;
        public enum condition
        {
            [Description("Not activated")]
            Disabled = 1,
            [Description("OK")]
            OK = 2,
            [Description("Suspended")]
            Suspended = 3,
        }

        public Client()
        {
            Condition = condition.Disabled;
            GenerateFLC();
        }

        void GenerateFLC()
        {
            const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            var random = new Random();
            firstLoginCode = new string(Enumerable.Repeat(chars, 10).Select(s => s[random.Next(s.Length)]).ToArray());
        }

        public void GenerateSessionID()
        {
            const string chars = "abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            var random = new Random();
            firstLoginCode = new string(Enumerable.Repeat(chars, 50).Select(s => s[random.Next(s.Length)]).ToArray());
        }
    }
}
