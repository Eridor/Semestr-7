using System;
using System.Collections.Generic;
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
using OD_Client.Models;

namespace OD_Client
{
    /// <summary>
    /// Interaction logic for LoginWindow.xaml
    /// </summary>
    public partial class LoginWindow : Window
    {
        private ServerConnection server;
        public LoginWindow()
        {
            server = ServerConnection.load;
            InitializeComponent();
        }

        private void LoginB_Click(object sender, RoutedEventArgs e)
        {
            MainWindow window = new MainWindow();
            window.Show();
            this.Close();
        }

        private void RegisterB_Click(object sender, RoutedEventArgs e)
        {
            RegisterWindow window = new RegisterWindow();
            window.Show();
            this.Close();
        }

        private void FirstLoginB_Click(object sender, RoutedEventArgs e)
        {
            FirstLoginWindow window = new FirstLoginWindow();
            window.Show();
            this.Close();
        }


        private void DevB_Click(object sender, RoutedEventArgs e)
        {
            server.EncryptMessage("test");
        }
    }
}
