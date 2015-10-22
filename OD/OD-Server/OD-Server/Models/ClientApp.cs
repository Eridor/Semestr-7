using System;
using System.Collections.Generic;
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
        public byte[] key;
        public string Login;

        public ClientApp()
        {
            Login = "";
            ServerCng = new ECDiffieHellmanCng();
        }

        public void getKey(byte[] clientPublicKey)
        {
            ServerCng.KeyDerivationFunction = ECDiffieHellmanKeyDerivationFunction.Hash;
            ServerCng.HashAlgorithm = CngAlgorithm.Sha512;
            key = ServerCng.DeriveKeyMaterial(CngKey.Import(clientPublicKey, CngKeyBlobFormat.EccPublicBlob));
        }
    }
}
