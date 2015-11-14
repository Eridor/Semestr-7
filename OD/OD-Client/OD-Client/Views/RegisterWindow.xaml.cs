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
    /// Interaction logic for RegisterWindow.xaml
    /// </summary>
    public partial class RegisterWindow : Window
    {
        public RegisterWindow()
        {
            InitializeComponent();
        }
        private ServerConnection serv = ServerConnection.load;
        private void ReturnB_Click(object sender, RoutedEventArgs e)
        {
            LoginWindow window = new LoginWindow();
            window.Show();
            this.Close();
        }

        private void RegisterB_Click(object sender, RoutedEventArgs e)
        {
            if (Pass.Password == Pass2.Password)
            {
                List<string> dataList = new List<string>();
                dataList.Add(Username.Text);
                dataList.Add(Pass.Password);
                dataList.Add(Email.Text);
                if (serv.StartCommunication(dataList, ServerConnection.MessageType.Register) == 0)
                {
                    FirstLoginWindow window = new FirstLoginWindow();
                    window.Show();
                    this.Close();
                }
                else
                {
                    //MessageBox.Show("Błąd:\nTransmisja nieudana");
                }
            }
            else
            {
                MessageBox.Show("Błąd:\nHasło do siebie nie pasuje");
            }
        }
    }
}
