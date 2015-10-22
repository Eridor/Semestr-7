using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace OD_Server
{
    class MessageExchange
    {
        private TcpListener serverListener;
        private static int serverPort = 8000;
        private Thread thread;
        private GlobalConfig conf;

        public MessageExchange()
        {
            conf = GlobalConfig.Instance;
            serverListener = TcpListener.Create(serverPort);
            thread = new Thread(new ThreadStart(imListening));
            
        }

        public void startListening()
        {
            thread.Start();
            serverListener.Start();
        }
        public void stopListening()
        {
            thread.Abort();
        }

        public void imListening()
        {
            while (true)
            {
                TcpClient connection = serverListener.AcceptTcpClient();
                NetworkStream ns = connection.GetStream();

                Byte[] dataRecived = new Byte[256];
                int bytes = ns.Read(dataRecived, 0, dataRecived.Length);
                string textRecived = System.Text.Encoding.ASCII.GetString(dataRecived, 0, bytes);

                string answer = Analize(textRecived);
                Byte[] data = System.Text.Encoding.ASCII.GetBytes(answer);
                ns.Write(data, 0, data.Length);

                ns.Close();
                connection.Close();
            }
        }

        private string Analize(string txt)
        {
            int code = Convert.ToInt32(txt.Take(2));
            string returnMessage = "";

            switch (code)
            {
                case 01:
                    string clientPublicKey = txt.Substring(2);
                    int clientId = conf.AddClientApp(clientPublicKey);
                    return "Hi" + conf.clientApps[clientId].id + conf.clientApps[clientId].key;
                    break;
                default:
                    // :(
                    break;
            }

            return returnMessage;
        }
    }
}
