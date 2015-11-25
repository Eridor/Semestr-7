using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace OD_Server.Models
{
    class TimeServer
    {
        private TcpListener serverListener;
        private static int serverPort = 9000;
        private Thread thread;
        private GlobalConfig conf;

        public TimeServer()
        {
            conf = GlobalConfig.Instance;
            serverListener = TcpListener.Create(serverPort);
            thread = new Thread(new ThreadStart(imListening));
        }

        public void startListening()
        {
            serverListener.Start();
            thread.Start();
            
        }
        public void stopListening()
        {
            
            thread.Abort();
            serverListener.Stop();
            
        }

        private void imListening()
        {
            while (true)
            {
                TcpClient connection = serverListener.AcceptTcpClient();
                NetworkStream ns = connection.GetStream();
                byte[] dataRecived = new byte[256];
                int bytes = ns.Read(dataRecived, 0, dataRecived.Length);
                string data = System.Text.Encoding.ASCII.GetString(dataRecived, 0, bytes);

                if (data == "thetime")
                {
                    byte[] ans = System.Text.Encoding.ASCII.GetBytes(generateData());
                    ns.Write(ans, 0, ans.Length);
                }
                else
                {
                    byte[] ans = System.Text.Encoding.ASCII.GetBytes("nope");
                    ns.Write(ans, 0, ans.Length);
                }
            }
        }

        public string generateData()
        {
            DateTime time = DateTime.Now;
            TimeSpan spantime = new TimeSpan(time.Ticks);
            double k = spantime.TotalSeconds;
            UInt64 ret = Convert.ToUInt64(k);
            return ret.ToString();
        }

    }

    
}
