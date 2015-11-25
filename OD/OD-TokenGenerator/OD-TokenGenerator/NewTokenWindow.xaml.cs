using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace OD_TokenGenerator
{
    /// <summary>
    /// Interaction logic for NewTokenWindow.xaml
    /// </summary>
    public partial class NewTokenWindow : Window
    {
        GlobalConfig conf = GlobalConfig.Instance;
        public NewTokenWindow()
        {
            InitializeComponent();
        }

        private void Generate_Click(object sender, RoutedEventArgs e)
        {
            TokenOutput.Text = generate();
        }

        private string generate()
        {
            const string chars = "0123456789";
            var random = new Random();
            string token = new string(Enumerable.Repeat(chars, 12).Select(s => s[random.Next(s.Length)]).ToArray());
            conf.tokenID = token;
            File.WriteAllText("token.toko", token);
            return token;
        }
    }
}
