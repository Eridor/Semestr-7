using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;

namespace OD_Client.Models
{
    class ServerConnection
    {
        private static ServerConnection instance;

        private ServerConnection()
        {
            AesClass = Aes.Create();
        }
        public static ServerConnection load
        {
            get 
            {
                if (instance == null)
                {
                    instance = new ServerConnection();
                }
                return instance;
            }
        }

        //---------------------------------------

        public static string ServerIp = "127.0.0.1";
        public static int ServerPort = 8000;
        private byte[] privateKey;
        private Aes AesClass;
        private ECDiffieHellmanCng DiffHellman;
        public string SendMessage(string text)
        {
            TcpClient client = new TcpClient(ServerIp, ServerPort);
            NetworkStream stream = client.GetStream();
            Byte[] data = System.Text.Encoding.ASCII.GetBytes(text);
            stream.Write(data, 0, data.Length);

            Byte[] dataRecived = new Byte[256];
            int bytes = stream.Read(data, 0, data.Length);
            string textRecived = System.Text.Encoding.ASCII.GetString(dataRecived, 0, bytes);

            stream.Close();
            client.Close();

            return textRecived;
        }

        public int DiffHell()
        {
            DiffHellman.KeyDerivationFunction = ECDiffieHellmanKeyDerivationFunction.Hash;
            DiffHellman.HashAlgorithm = CngAlgorithm.Sha512;
            byte[] publicKey = DiffHellman.PublicKey.ToByteArray();

            string ans = SendMessage("Hello" + publicKey);

            if (ans.Take(2) == "Hi")
            {
                byte[] serverPublicKey = System.Text.Encoding.ASCII.GetBytes(ans.Substring(3));
                CngKey k = CngKey.Import(serverPublicKey, CngKeyBlobFormat.EccPublicBlob);
                privateKey = DiffHellman.DeriveKeyMaterial(k);

            }
            return 0;
        }

        public string EncryptMessage(string text)
        {
            return "";
        }

    }
}
