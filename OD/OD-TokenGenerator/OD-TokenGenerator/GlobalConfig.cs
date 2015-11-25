using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace OD_TokenGenerator
{
    internal class GlobalConfig
    {
        private static GlobalConfig instance;

        public static GlobalConfig Instance
        {
            get
            {
                if (instance == null)
                    instance = new GlobalConfig();
                return instance;
            }
        }

        public GlobalConfig()
        {
            if (!File.Exists("token.toko"))
            {
                tokenID = null;
            }
            else
            {
                tokenID = File.ReadAllText("token.toko");
            }
            
        }

        public string tokenID;

        public string GetServerTime()
        {
            string ip = File.ReadAllText("conf");
            TcpClient cli = new TcpClient(ip, 9000);
            NetworkStream ns = cli.GetStream();
            Byte[] data = System.Text.Encoding.ASCII.GetBytes("thetime");
            ns.Write(data, 0, data.Length);
            data = new Byte[256];
            Int32 bytes = ns.Read(data, 0, data.Length);
            string ans = System.Text.Encoding.ASCII.GetString(data, 0, bytes);
            return ans;
        }

        public long TimeLeft(string time)
        {
            return Convert.ToInt64(time)%30;
        }

        public string GenerateTokenCode(string tim)
        {
            long time = Convert.ToInt64(tim);
            long time2 = time%30;

            long t = time - time2;
            long k = Convert.ToInt64(tokenID)%t;

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
                for(int i = 0; i<13; i++)
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
                string outp = (Convert.ToInt64(numb)%99999999).ToString();
                return outp;
            }
        }
    }

}
