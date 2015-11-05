using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Xml;

namespace OD_Client.Models
{
    class ServerConnection
    {
        private static ServerConnection instance;

        private ServerConnection()
        {
            AesClass = Aes.Create();
            AesClass.IV = new byte[16] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            DiffHellman = new ECDiffieHellmanCng();
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
        private int myId;
        private byte[] privateKey;
        private Aes AesClass;
        private ECDiffieHellmanCng DiffHellman;
        public string SendMessage(string text)
        {
            try
            {
                TcpClient client = new TcpClient(ServerIp, ServerPort);
                NetworkStream stream = client.GetStream();
                Byte[] data = System.Text.Encoding.UTF8.GetBytes(text);
                stream.Write(data, 0, data.Length);

                Byte[] dataRecived = new Byte[256];
                int bytes = stream.Read(dataRecived, 0, dataRecived.Length);
                string textRecived = System.Text.Encoding.UTF8.GetString(dataRecived, 0, bytes);

                stream.Close();
                client.Close();

                return textRecived;
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.ToString(), "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            return null;
        }

        public int DiffHell()
        {
            try
            {
                TcpClient client = new TcpClient(ServerIp, ServerPort);
                NetworkStream stream = client.GetStream();

                DiffHellman.KeyDerivationFunction = ECDiffieHellmanKeyDerivationFunction.Hash;
                DiffHellman.HashAlgorithm = CngAlgorithm.Sha256;
                byte[] publicKey = DiffHellman.PublicKey.ToByteArray();
                /*
                string outputKey = "";

                foreach (byte item in publicKey)
                {
                    outputKey += (char) item;
                }
                */

                Byte[] data = System.Text.Encoding.ASCII.GetBytes("00");
                stream.Write(data, 0, data.Length);
                Byte[] dataRecived = new Byte[256];
                int bytes = stream.Read(dataRecived, 0, dataRecived.Length);
                string textRecived = System.Text.Encoding.ASCII.GetString(dataRecived, 0, bytes);
                if (textRecived.Substring(0,2) == "Hi")
                {
                    Byte[] dataRecivedKey = new Byte[140];
                    myId = Convert.ToInt32(textRecived[2]);
                    stream.Write(publicKey, 0, publicKey.Length);
                    bytes = stream.Read(dataRecivedKey, 0, dataRecivedKey.Length);
                    byte[] send = System.Text.Encoding.ASCII.GetBytes("ack");
                    stream.Write(send, 0, send.Length);
                    Byte[] dataRecived2 = new Byte[256];
                    int bytes2 = stream.Read(dataRecived2, 0, dataRecived2.Length);
                    if (System.Text.Encoding.ASCII.GetString(dataRecived2,0, dataRecived2.Length).Substring(0,6) == "ackack")
                    {
                        CngKey k = CngKey.Import(dataRecivedKey, CngKeyBlobFormat.EccPublicBlob);
                        privateKey = DiffHellman.DeriveKeyMaterial(k);
                        AesClass.Key = privateKey;
                    }

                }

                stream.Close();
                client.Close();
            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.ToString(), "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return -1;
            }
            return 0;
        }

        public byte[] EncryptMessage(string text)
        {
            byte[]  encrypted;
            ICryptoTransform encryptor = AesClass.CreateEncryptor(AesClass.Key, AesClass.IV);
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

        public string DecryptMessage(byte[] text)
        {
            string output;
            ICryptoTransform decryptor = AesClass.CreateDecryptor(AesClass.Key, AesClass.IV);
            using (MemoryStream msDecrypt = new MemoryStream(text))
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
    }
}
