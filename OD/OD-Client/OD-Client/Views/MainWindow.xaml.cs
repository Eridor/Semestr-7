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
using System.Windows.Navigation;
using System.Windows.Shapes;
using OD_Client.Models;

namespace OD_Client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        
        private ServerConnection serv = ServerConnection.load;
        public MainWindow()
        {
            InitializeComponent();
        }

        private void LogoutB_Click(object sender, RoutedEventArgs e)
        {
             List<string> dataList = new List<string>();
            if (serv.StartCommunication(dataList, ServerConnection.MessageType.Logout) == 0 || 1 == 1)
            {
                LoginWindow window = new LoginWindow();
                window.Show();
                this.Close();
            }
        }

        private void EraseAccB_Click(object sender, RoutedEventArgs e)
        {
            LoginWindow window = new LoginWindow();
            window.Show();
            this.Close();
        }
    }
}
