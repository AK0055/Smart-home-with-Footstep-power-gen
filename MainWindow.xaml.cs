using System;
using System.IO.Ports;
using System.Windows;
using System.Windows.Controls;
namespace wpfApp2
{
    public partial class MainWindow : Window
    {
        SerialPort port;
        public void Main()
        {
            InitializeComponent();
        }
        private void Buttonclick1(object sender, RoutedEventArgs e)
        {
            try
            {
                port = new SerialPort("COM1", 9600, Parity.None, 8);
                if (!String.IsNullOrEmpty(txtCom.Text))
                {
                    port.Open();
                    port.WriteLine(txtCom.Text);
                    port.Close();
                }
                else MessageBox.Show("Please insert a text in the field");
            }
            catch (ApplicationException caught)
            {
                MessageBox.Show(caught.Data.ToString());
            }

        }
    }
    
}