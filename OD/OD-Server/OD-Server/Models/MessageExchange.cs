using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Security.Cryptography;
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

        private static byte[] sIV = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        public MessageExchange()
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
            serverListener.Stop();
            thread.Abort();
        }

        private void imListening()
        {
            while (true)
            {
                TcpClient connection = serverListener.AcceptTcpClient();
                NetworkStream ns = connection.GetStream();

                byte[] dh = DiffHell(ns);

                Analize(ns, dh);

                ns.Close();
                connection.Close();
            }
        }

        private int Analize(NetworkStream ns, byte[] privateKey)
        {
            byte[] dataRecived = new byte[256];
            string[] msg = new string[5];
            int bytes = ns.Read(dataRecived, 0, dataRecived.Length);
            string textRecived = DecryptMessage(dataRecived, privateKey);
            int i = 0;


            foreach (char item in textRecived)
            {
                if (item == (char) 0)
                    i++;
                else
                    msg[i] += item;
            }

            string passRecived;
            byte[] password;
            byte[] send;
            switch (msg[0])
            {
                case "reg":
                    bytes = ns.Read(dataRecived, 0, dataRecived.Length);
                    passRecived = DecryptMessage(dataRecived, privateKey);
                    password = StringToByte(passRecived);
                    string FLC = conf.AddClient(msg[1], password, msg[2]); //User, email
                    
                    if (FLC == "error:login")
                    {
                        send = EncryptMessage(FLC, privateKey);
                    }
                    else
                    {
                        send = EncryptMessage(FLC, privateKey);
                    }
                    ns.Write(send, 0, send.Length);
                    break;
                case "1lg":
                    bytes = ns.Read(dataRecived, 0, dataRecived.Length);
                    passRecived = DecryptMessage(dataRecived, privateKey);
                    password = StringToByte(passRecived);
                    string sessionKey = conf.FirstLogin(msg[1], password, msg[2], msg[3]); //User, Sec code, token
                    break;
            }

            return 0;
        }

        

        public byte[] DiffHell(NetworkStream ns)
        {
            try
            {
                ECDiffieHellmanCng DiffHellman = new ECDiffieHellmanCng();

                DiffHellman.KeyDerivationFunction = ECDiffieHellmanKeyDerivationFunction.Hash;
                DiffHellman.HashAlgorithm = CngAlgorithm.Sha256;
                byte[] publicKey = DiffHellman.PublicKey.ToByteArray();

                Byte[] dataRecivedKey = new Byte[140];

                
                int bytes = ns.Read(dataRecivedKey, 0, dataRecivedKey.Length);
                ns.Write(publicKey, 0, publicKey.Length);
                CngKey k = CngKey.Import(dataRecivedKey, CngKeyBlobFormat.EccPublicBlob);
                byte[] privateKey = DiffHellman.DeriveKeyMaterial(k);
                return privateKey;


            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.ToString(), "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return null;
            }
        }

        public byte[] EncryptMessage(string text, byte[] key)
        {
            byte[] encrypted;
            Aes AesClass = Aes.Create();
            AesClass.IV = sIV;
            ICryptoTransform encryptor = AesClass.CreateEncryptor(key, AesClass.IV);
            using (MemoryStream msEncrypt = new MemoryStream())
            {
                using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                {
                    using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                    {
                        swEncrypt.Write(text);

                    }
                    encrypted = msEncrypt.ToArray();
                }
            }
            return encrypted;
        }

        public string DecryptMessage(byte[] text, byte[] key)
        {

            byte[] input = CutEmptyBytes(text);
            
            string output;
            Aes AesClass = Aes.Create();
            AesClass.Key = key;
            AesClass.IV = sIV;
            ICryptoTransform decryptor = AesClass.CreateDecryptor(key, AesClass.IV);
            using (MemoryStream msDecrypt = new MemoryStream(input))
            {
                using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                {
                    using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                    {
                        output = srDecrypt.ReadToEnd();
                    }
                }
            }

            return output;
        }

        private byte[] StringToByte(string txt)
        {
            byte[] output = new byte[txt.Length];
            int i = 0;
            foreach (var item in txt)
            {
                output[i] = (byte) item;
            }
            return output;
        }

        public byte[] CutEmptyBytes(byte[] input)
        {
            int count = 0;
            for (int i = (input.Length) - 1; i > 0; i--)
            {
                if (input[i] != 0)
                {
                    count = i + 1;
                    break;
                }
            }
            int buff = count;
            /*
            for (int i = 0; i <= 8; i++ )
            {
                if (Math.Pow(2,i) >= count)
                {
                    buff = (int)Math.Pow(2,i);
                    break;
                }
            }
            */
            byte[] outBytes = new byte[buff];
            for (int i = 0; i < count; i++)
            {
                outBytes[i] = input[i];
            }
            return outBytes;
        }
    }
}
