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
    /// Interaction logic for LoadTokenWindow.xaml
    /// </summary>
    public partial class LoadTokenWindow : Window
    {
        GlobalConfig conf = GlobalConfig.Instance;
        public LoadTokenWindow()
        {
            InitializeComponent();
        }

        private void LoadToken_Click(object sender, RoutedEventArgs e)
        {
            conf.tokenID = TokenBox.Text;
            File.WriteAllText("token.toko", conf.tokenID);
        }
    }
}
