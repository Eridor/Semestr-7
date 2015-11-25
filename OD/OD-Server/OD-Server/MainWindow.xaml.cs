using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading;
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
using OD_Server.Models;

namespace OD_Server
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GlobalConfig conf;
        private MessageExchange server;
        private TimeServer timeserv;
        private Thread Refresh;
        public MainWindow()
        {
            //ConsoleManager.Show();
            conf = GlobalConfig.Instance;
            server = new MessageExchange();
            timeserv = new TimeServer();
            InitializeComponent();

            Refresh = new Thread(new ThreadStart(RefreshListF));
            
            server.startListening();
            timeserv.startListening();
            Refresh.Start();

            string t = timeserv.generateData();
            

        }
        private void RefreshListF()
        {
            while (true)
            {

                this.Dispatcher.Invoke((Action)(() =>
                {
                    ClientList.Text = DownloadClientList();
                    if (ClientList.Text == "")
                    {
                        ClientList.Text = ">> BRAK KLIENTÓW <<";
                    }
                }));
                Thread.Sleep(1000);
            }
        }

        private string DownloadClientList()
        {
            string output = "";
            foreach (Client item in conf.clientList)
            {
                output += item.Login + ", " + item.email;
                output += ", stan: " + item.Condition;
                if (item.sessionID != null)
                {
                    output += ", zalogowany(" + item.sessionID + ")";
                }
                
                foreach (string it in item.messages)
                {
                    output += "\n>> " + it;
                }
                output += "\n";
            }
            return output;
        }

        protected override void OnClosed(EventArgs e)
        {
            Refresh.Abort();
            Environment.Exit(0);
            //timeserv.stopListening();
            //server.stopListening();
            
            //base.OnClosed(e);
        }
    }
}
