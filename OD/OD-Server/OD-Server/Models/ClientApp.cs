using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace OD_Server.Models
{
    class ClientApp
    {
        public int id;
        public ECDiffieHellmanCng ServerCng;
        public Aes AesClass;
        public byte[] key;
        public byte[] hisKey;
        public string Login;

        public ClientApp()
        {
            Login = "";
            ServerCng = new ECDiffieHellmanCng();
            AesClass = Aes.Create();
            AesClass.IV = new byte[16] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        }

        public void getKey()
        {
            ServerCng.KeyDerivationFunction = ECDiffieHellmanKeyDerivationFunction.Hash;
            ServerCng.HashAlgorithm = CngAlgorithm.Sha256;
            //
            CngKey k = CngKey.Import(hisKey, CngKeyBlobFormat.EccPublicBlob);
            key = ServerCng.DeriveKeyMaterial(CngKey.Import(hisKey, CngKeyBlobFormat.EccPublicBlob));
        }

        public byte[] EncryptMessage(string text)
        {
            byte[] encrypted;
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
