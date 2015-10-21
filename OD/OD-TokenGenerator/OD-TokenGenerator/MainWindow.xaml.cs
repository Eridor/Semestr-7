﻿using System;
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

namespace OD_TokenGenerator
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
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
    }
}
