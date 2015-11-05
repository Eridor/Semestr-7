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
using System.Windows.Annotations;
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
        private string SessionKey;
        public enum MessageType {Register, FirstLogn, Login, Message, Logout}

        public int StartCommunication(List<String> data, MessageType type)
        {
            try
            {
                TcpClient client = new TcpClient(ServerIp, ServerPort);
                NetworkStream stream = client.GetStream();

                byte[] key = DiffHell(stream);
                if (key != null)
                {
                    ExchangeMessages(stream, data, type);
                }
                stream.Close();
                client.Close();
                return 0;
            }
            catch (Exception e)
            {
                MessageBox.Show("Błąd transmisji danych:\n" + e);
                return -1;
            }
        }

        private void ExchangeMessages(NetworkStream ns, List<String> data, MessageType type)
        {
            string sendText = ""; 
            string ans ="";
            Byte[] ansBytes = new Byte[255];
            switch (type)
            {
                case MessageType.Register:
                    sendText = "reg" + (char)0 + data[0] + (char)0 + data[2];
                    ns.Write(EncryptMessage(sendText), 0, Encoding.UTF8.GetBytes(sendText).Length);
                    ns.Write(hashPass(data[1]), 0 , hashPass(data[1]).Length);
                    
                    ns.Read(ansBytes, 0, ansBytes.Length);
                    ans = Encoding.UTF8.GetString(ansBytes);
                    if (ans != "error")
                    {
                        MessageBox.Show("Klucz pierwszego logowania: " + ans);
                    }
                    break;
                case MessageType.FirstLogn:
                    sendText = "log" + (char)0 + data[0] + (char)0 + data[2] + (char)0 + data[3];
                    ns.Write(EncryptMessage(sendText), 0, Encoding.UTF8.GetBytes(sendText).Length);
                    ns.Write(hashPass(data[1]), 0 , hashPass(data[1]).Length);

                    ans = Encoding.UTF8.GetString(ansBytes);
                    if (ans != "error")
                    {
                        SessionKey = ans;
                        MessageBox.Show("Zalogowany: " + ans);
                    }
                    break;
                default:
                    break;
            }


        }

        private byte[] hashPass(string pass)
        {
            SHA256 sha256 = SHA256.Create();
            return sha256.ComputeHash(Encoding.UTF8.GetBytes(pass));

        }
        /// Old imp
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

        public byte[] DiffHell(NetworkStream ns)
        {
            try
            {

                DiffHellman.KeyDerivationFunction = ECDiffieHellmanKeyDerivationFunction.Hash;
                DiffHellman.HashAlgorithm = CngAlgorithm.Sha256;
                byte[] publicKey = DiffHellman.PublicKey.ToByteArray();

                Byte[] dataRecivedKey = new Byte[140];

                ns.Write(publicKey, 0, publicKey.Length);
                int bytes = ns.Read(dataRecivedKey, 0, dataRecivedKey.Length);
                
                CngKey k = CngKey.Import(dataRecivedKey, CngKeyBlobFormat.EccPublicBlob);
                privateKey = DiffHellman.DeriveKeyMaterial(k);
                AesClass.Key = privateKey;
                    

            }
            catch (Exception exception)
            {
                MessageBox.Show(exception.ToString(), "Error", MessageBoxButton.OK, MessageBoxImage.Error);
                return null;
            }
            return privateKey;
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
