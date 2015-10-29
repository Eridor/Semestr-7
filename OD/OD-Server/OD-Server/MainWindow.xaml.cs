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

namespace OD_Server
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GlobalConfig conf;
        private MessageExchange server;
        public MainWindow()
        {
            conf = GlobalConfig.Instance;
            server = new MessageExchange();
            InitializeComponent();

        }

        private void StartB_Click(object sender, RoutedEventArgs e)
        {
            server.startListening();
        }
    }
}
