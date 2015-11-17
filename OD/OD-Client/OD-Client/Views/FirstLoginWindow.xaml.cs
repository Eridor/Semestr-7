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
    /// Interaction logic for FirstLoginWindow.xaml
    /// </summary>
    public partial class FirstLoginWindow : Window
    {
        private ServerConnection serv = ServerConnection.load;
        public FirstLoginWindow()
        {
            
            InitializeComponent();
            SecurityCode.Text = serv.KPL;
        }

        private void LoginB_Click(object sender, RoutedEventArgs e)
        {
                List<string> dataList = new List<string>();
                dataList.Add(Username.Text);
                dataList.Add(Pass.Password);
                dataList.Add(SecurityCode.Text);
                dataList.Add(TokenID.Text);
                if (serv.StartCommunication(dataList, ServerConnection.MessageType.FirstLogn) == 0)
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

        private void Goback_Click(object sender, RoutedEventArgs e)
        {
            LoginWindow window = new LoginWindow();
            window.Show();
            this.Close();
        }
    }
}
