using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
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

namespace OD_TokenGenerator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GlobalConfig conf;
        private Thread refresh;

        public MainWindow()
        {
            InitializeComponent();
            conf = GlobalConfig.Instance;
            refresh = new Thread(new ThreadStart(refreshData));
            refresh.Start();
        }

        private void refreshData()
        {
            while (true)
            {
                if (conf.tokenID != null)
                {
                    try
                    {
                        string time = conf.GetServerTime();
                        long timeleft = 29 - conf.TimeLeft(time);
                        this.Dispatcher.Invoke((Action) (() =>
                        {
                            TokenID.Text = conf.tokenID;
                            TimeLeftBox.Text = timeleft.ToString() + "s";
                            TokenProgressBar.Value = timeleft;
                            if (timeleft < 3)
                                TokenProgressBar.Foreground = Brushes.DarkRed;
                            else if (timeleft < 6)
                                TokenProgressBar.Foreground = Brushes.Red;
                            else if (timeleft < 9)
                                TokenProgressBar.Foreground = Brushes.OrangeRed;
                            else if (timeleft < 12)
                                TokenProgressBar.Foreground = Brushes.Orange;
                            else if (timeleft < 16)
                                TokenProgressBar.Foreground = Brushes.Yellow;
                            else if (timeleft < 21)
                                TokenProgressBar.Foreground = Brushes.LawnGreen;
                            else
                                TokenProgressBar.Foreground = Brushes.Green;


                            if (TokenID != null)
                            {
                                TokenCodeBox.Text = conf.GenerateTokenCode(time);
                            }
                            ErrorBox.Text = "";
                        }));
                    }
                    catch (Exception e)
                    {
                        this.Dispatcher.Invoke((Action)(() =>
                        {
                            TokenID.Text = conf.tokenID;
                            ErrorBox.Text = "Błąd połączenia z serwerem czasu";
                            TokenCodeBox.Text = "########";
                            TimeLeftBox.Text = "--s";
                        }));
                        Thread.Sleep(9000);
                    }
                }
                else
                    {
                        this.Dispatcher.Invoke((Action) (() =>
                        {
                            TokenCodeBox.Text = "Brak";
                            TimeLeftBox.Text = "--s";
                            TokenProgressBar.Value = 0;
                            TokenID.Text = "Wygeneruj nowy token";
                        }));

                    }
                    Thread.Sleep(1000);
            }
            
        }

        private void NewTokenB_Click(object sender, RoutedEventArgs e)
        {
            NewTokenWindow w = new NewTokenWindow();
            w.Show();
        }

        private void LoadTokenB_Click(object sender, RoutedEventArgs e)
        {
            LoadTokenWindow w = new LoadTokenWindow();
            w.Show();
        }

        protected override void OnClosed(EventArgs e)
        {
            refresh.Abort();
            base.OnClosed(e);
        }

    }
}
