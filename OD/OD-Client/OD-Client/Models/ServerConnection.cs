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
            KPL = "";
            login = "";
            ServerIp = File.ReadAllText("conf");
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

        public string ServerIp;
        public static int ServerPort = 8000;
        private int myId;
        private byte[] privateKey;
        private Aes AesClass;
        private ECDiffieHellmanCng DiffHellman;
        public string login;
        public string SessionKey;
        public enum MessageType {Register, FirstLogn, Login, Message, Logout}

        public string KPL;
        public int StartCommunication(List<String> data, MessageType type)
        {
            try
            {
                TcpClient client = new TcpClient(ServerIp, ServerPort);
                NetworkStream stream = client.GetStream();

                byte[] key = DiffHell(stream);
                int code = 0;
                if (key != null)
                {
                    code = ExchangeMessages(stream, data, type);
                }
                stream.Close();
                client.Close();
                return code;
            }
            catch (Exception e)
            {
                MessageBox.Show("Błąd: nie można się połączyć z serwerem\n" + e);
                return -1;
            }
        }

        private int ExchangeMessages(NetworkStream ns, List<String> data, MessageType type)
        {
            string sendText = ""; 
            string ans ="";
            byte[] outBytes;
            Byte[] ansBytes = new Byte[255];
            switch (type)
            {
                case MessageType.Register:
                    sendText = "reg" + (char)0 + data[0] + (char)0 + data[2];
                    outBytes = EncryptMessage(sendText);
                    ns.Write(outBytes, 0, outBytes.Length);
                    outBytes = EncryptMessage(ByteToString(hashPass(data[1])));
                    ns.Write(outBytes, 0, outBytes.Length);
                    
                    ns.Read(ansBytes, 0, ansBytes.Length);
                    ans = DecryptMessage(ansBytes);
                    if (ans.Substring(0, 5) != "error")
                    {
                        KPL = ans;
                        MessageBox.Show("Klucz pierwszego logowania: " + ans);

                    }
                    else
                    {
                        if (ans.Substring(6, 5) == "login")
                        {
                            MessageBox.Show("Login zajęty");
                            return -1;
                        }
                    }
                    break;
                case MessageType.FirstLogn:
                    sendText = "1lg" + (char)0 + data[0] + (char)0 + data[2] + (char)0 + data[3];
                    outBytes = EncryptMessage(sendText);
                    ns.Write(outBytes, 0, outBytes.Length);
                    outBytes = EncryptMessage(ByteToString(hashPass(data[1])));
                    ns.Write(outBytes, 0, outBytes.Length);

                    ns.Read(ansBytes, 0, ansBytes.Length);
                    ans = DecryptMessage(ansBytes);
                    if (ans.Substring(0, 5) != "error")
                    {
                        SessionKey = ans;
                        login = data[0];
                        MessageBox.Show("Zalogowany: " + login);

                    }
                    else
                    {
                        //if (ans.Substring(6, 5) == "login")
                        {
                            MessageBox.Show("Błąd: " + ans);
                            return -1;
                        }
                    }
                    break;
                    case MessageType.Login:
                    sendText = "log" + (char)0 + data[0] + (char)0 + data[2];
                    outBytes = EncryptMessage(sendText);
                    ns.Write(outBytes, 0, outBytes.Length);
                    outBytes = EncryptMessage(ByteToString(hashPass(data[1])));
                    ns.Write(outBytes, 0, outBytes.Length);

                    ns.Read(ansBytes, 0, ansBytes.Length);
                    ans = DecryptMessage(ansBytes);
                    if (ans.Substring(0,5) != "error")
                    {
                        SessionKey = ans;
                        login = data[0];
                        MessageBox.Show("Zalogowany: " + login);
                    }
                    else
                    {
                        //if (ans.Substring(6, 5) == "login")
                        {
                            MessageBox.Show("Błąd: " + ans);
                            return -1;
                        }
                    }
                    break;
                    case MessageType.Logout:
                    sendText = "out" + (char)0 + login + (char)0 + SessionKey;
                    outBytes = EncryptMessage(sendText);
                    ns.Write(outBytes, 0, outBytes.Length);

                    ns.Read(ansBytes, 0, ansBytes.Length);
                    ans = DecryptMessage(ansBytes);
                    if (ans == "oki")
                    {
                        login = "";
                        SessionKey = null;
                        MessageBox.Show("Wylogowany: " + ans);
                    }
                    else
                    {
                        //if (ans.Substring(6, 5) == "login")
                        {
                            MessageBox.Show("Błąd: " + ans);
                            return -1;
                        }
                    }
                    break;
                    case MessageType.Message:
                    sendText = "msg" + (char)0 + login + (char)0 + SessionKey + (char)0 + data[0];
                    outBytes = EncryptMessage(sendText);
                    ns.Write(outBytes, 0, outBytes.Length);

                    ns.Read(ansBytes, 0, ansBytes.Length);
                    ans = DecryptMessage(ansBytes);
                    if (ans == "oki")
                    {
                        MessageBox.Show("Wiadomość dostarczona: " + ans);
                    }
                    else
                    {
                        //if (ans.Substring(6, 5) == "login")
                        {
                            MessageBox.Show("Błąd: " + ans);
                            return -1;
                        }
                    }
                    break;
                default:
                    return -1;
                    break;
            }
            return 0;

        }

        private byte[] hashPass(string pass)
        {
            SHA256 sha256 = SHA256.Create();
            return sha256.ComputeHash(Encoding.UTF8.GetBytes(pass));

        }

        private string ByteToString(byte[] inBytes)
        {
            string outData = "";
            foreach (var item in inBytes)
            {
                outData += (char) item;
            }
            return outData;
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
            byte[] input = CutEmptyBytes(text);
            ICryptoTransform decryptor = AesClass.CreateDecryptor(AesClass.Key, AesClass.IV);
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
