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

        private void imListening()
        {
            while (true)
            {
                TcpClient connection = serverListener.AcceptTcpClient();
                NetworkStream ns = connection.GetStream();

                Byte[] dataRecived = new Byte[256];
                int bytes = ns.Read(dataRecived, 0, dataRecived.Length);
                string textRecived = System.Text.Encoding.ASCII.GetString(dataRecived, 0, bytes);

                string answer = Analize(textRecived, ns);
                if (answer == "1000")
                {
                    answer = Analize(EncryptMessage(dataRecived));
                }
                Byte[] data = System.Text.Encoding.ASCII.GetBytes(answer);
                ns.Write(data, 0, data.Length);

                ns.Close();
                connection.Close();
            }
        }

        private string Analize(string txt, NetworkStream ns)
        {
            string sCode = new string(txt.Take(2).ToArray());
            int code = Convert.ToInt32(sCode);
            string returnMessage = "";

            switch (code)
            {
                case 00:

                    int clientId = conf.AddClientApp() -1;
                    
                    byte[] send = System.Text.Encoding.ASCII.GetBytes("Hi" + conf.clientApps[clientId].id);
                    ns.Write(send, 0, send.Length);
                    byte[] key = new byte[140];
                    ns.Read(key, 0, key.Length);
                    conf.clientApps[clientId].hisKey = key;
                    byte[] sendKey = conf.clientApps[clientId].ServerCng.PublicKey.ToByteArray();
                    ns.Write(sendKey, 0, 140);
                    byte[] buff = new byte[140];
                    ns.Read(buff, 0, buff.Length);
                    if (Encoding.ASCII.GetString(buff, 0, buff.Length).Substring(0,3) == "ack")
                    {
                        conf.clientApps[clientId].getKey();
                        return "ackack";
                    }
                    return "Error";
                    break;
                default:
                    return "1000";
                    break;
            }

            return returnMessage;
        }
        public string EncryptMessage(byte[] text)
        {
            return "";
        }

        public byte[] DecryptMessage(string text)
        {
            return null;
        }

    }
}
