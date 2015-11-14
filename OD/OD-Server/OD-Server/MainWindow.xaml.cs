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

namespace OD_Server
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GlobalConfig conf;
        private MessageExchange server;
        private Thread Refresh;
        public MainWindow()
        {
            //ConsoleManager.Show();
            conf = GlobalConfig.Instance;
            server = new MessageExchange();
            InitializeComponent();

            Refresh = new Thread(new ThreadStart(RefreshListF));
            
            server.startListening();
            Refresh.Start();

        }
        private void RefreshListF()
        {
            while (true)
            {

                this.Dispatcher.Invoke((Action)(() =>
                {
                    ClientList.Text = DownloadClientList();
                }));
                Thread.Sleep(1000);
            }
        }

        private string DownloadClientList()
        {
            string output = "";
            foreach (Client item in conf.clientList)
            {
                output += item.Login;
                output += ", stan: " + item.Condition;
                output += "\n";
            }
            return output;
        }

        protected override void OnClosed(EventArgs e)
        {
            Refresh.Abort();
            server.stopListening();
            base.OnClosed(e);
            

        }
    }
}
