using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;
using System.IO.Ports;

namespace Mühendislik_Tasarimi
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int[] Baglanti_Hizlari = new int[] { 110, 300, 600, 1200, 2400, 4800, 9600, 19200 };
        int[] Data_Bits = new int[] { 5, 6, 7, 8 };
        int saniye = 0;
        string Gelen_Veri;

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Enabled = false;
            if(serialPort1.IsOpen)
            {
                serialPort1.Close();
            }
            BildirimMesajı.Text = "Lütfen Baglantı Ayarlarinizi Yapiniz";
            string[] Com_Ports = SerialPort.GetPortNames();
            foreach (string port in Com_Ports)
            {
                comPort.Items.Add(port);
            }
            foreach (int port in Baglanti_Hizlari)
            {
                BaudRate.Items.Add(port);
            }
            foreach (int port in Data_Bits)
            {
                Databits.Items.Add(port);
            }
            Parity.Items.AddRange(Enum.GetNames(typeof(System.IO.Ports.Parity)));
            StopBit.Items.AddRange(Enum.GetNames(typeof(System.IO.Ports.StopBits)));
        }

        private void BaudRate_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void baglan_Click(object sender, EventArgs e)
        {
            //Seri portun ayarlarını yüklüyoruz
            if (baglan.Text == "BAGLAN")
            {
                timer1.Enabled = true;
                try
                {
                    serialPort1.PortName = comPort.SelectedItem.ToString();
                    serialPort1.BaudRate = int.Parse(BaudRate.SelectedItem.ToString());
                    serialPort1.Parity = (System.IO.Ports.Parity)Enum.
                    Parse(typeof(System.IO.Ports.Parity), Parity.SelectedItem.ToString());
                    serialPort1.DataBits = int.Parse(Databits.SelectedItem.ToString());
                    serialPort1.StopBits = (System.IO.Ports.StopBits)Enum.
                    Parse(typeof(System.IO.Ports.StopBits), StopBit.SelectedItem.ToString());
                    serialPort1.Open();
                    baglan.Text = "KOPAR";
                    BildirimMesajı.Text = comPort.SelectedItem.ToString() + " Baglandı";
                    foreach (Control kontrol in groupBox1.Controls)
                    {
                        if (kontrol is ComboBox)
                        {
                            kontrol.Enabled = false;
                        }
                   }
                }
                catch(Exception hata)
                {
                    MessageBox.Show(hata.Message);
                }
                
             }    
           else
            {
                serialPort1.Close();
                baglan.Text = "BAGLAN";
                foreach (Control kontrol in groupBox1.Controls)
                {
                    if (kontrol is ComboBox)
                    {
                        kontrol.Enabled = true;
                    }
                }
                BildirimMesajı.Text = "Baglantı Ayarlarını Yapiniz....";
                timer1.Enabled = false;
            }
            
        }
        

        private void button1_Click(object sender, EventArgs e)
        {
                        
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            saniye++;
            if (saniye == 1)
            {
               Gelen_Veri= serialPort1.ReadLine();
               label8.Text = Gelen_Veri.ToString();
               listBox1.Items.Add(Gelen_Veri.ToString());
            }
            if (saniye == 2)
            {
                Gelen_Veri = serialPort1.ReadLine();               
                label9.Text = Gelen_Veri.ToString();
                listBox1.Items.Add(Gelen_Veri.ToString());
                saniye = 0;
            }
        }
    }
}
