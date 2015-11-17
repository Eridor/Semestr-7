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
        private ServerConnection serv;
        public LoginWindow()
        {
            serv = ServerConnection.load;
            InitializeComponent();
            System.Diagnostics.Debug.WriteLine("Debug");

        }

        private void LoginB_Click(object sender, RoutedEventArgs e)
        {
            List<string> dataList = new List<string>();
            dataList.Add(UserBox.Text);
            dataList.Add(PassBox.Password);
            dataList.Add(TokenBox.Text);
            if (serv.StartCommunication(dataList, ServerConnection.MessageType.Login) == 0)
            {
                MainWindow window = new MainWindow();
                window.Show();
                this.Close();
            }
            else
            {
                MessageBox.Show("Błąd:\nTransmisja nieudana");
            }
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


    }
}
