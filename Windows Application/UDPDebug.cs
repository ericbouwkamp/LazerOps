using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace lazerWin
{
    public partial class UDPDebug : Form
    {
        public UDPDebug()
        {
            InitializeComponent();
            if (UDP.connected == true)
            {
                connectedIndicator.Text = "   Connected";
                connectedIndicator.ForeColor = Color.Green;
                sendUDP.Enabled = true;
                SendAndReceiveUDP.Enabled = true;
                initUDP.Enabled = false;
                deinitUDP.Enabled = true;
            }
        }

        private void initUDP_Click(object sender, EventArgs e)
        {
            if (UDP.connect())
            {
                connectedIndicator.Text = "   Connected";
                connectedIndicator.ForeColor = Color.Green;
                sendUDP.Enabled = true;
                SendAndReceiveUDP.Enabled = true;
                initUDP.Enabled = false;
                deinitUDP.Enabled = true;
            }
        }

        private void deinitUDP_Click(object sender, EventArgs e)
        {
            if (UDP.disconnect())
            {
                connectedIndicator.Text = "Disconnected";
                connectedIndicator.ForeColor = Color.Red;
                sendUDP.Enabled = false;
                SendAndReceiveUDP.Enabled = false;
                initUDP.Enabled = true;
                deinitUDP.Enabled = false;
            }
        }

        private void sendUDP_Click(object sender, EventArgs e)
        {
            uint cmdVal = (uint)sendCmdVal.Value;
            uint dataVal = (uint)sendDataVal.Value;
            UDP.send(cmdVal, dataVal);
        }

        private void sendCmdVal_ValueChanged(object sender, EventArgs e)
        {

        }

        private void SendAndReceiveUDP_Click(object sender, EventArgs e)
        {
            int cmd = 0;
            int data = 0;
            UDP.receive(ref cmd, ref data);
            Console.WriteLine(cmd);
            Console.WriteLine(data);
        }
    }
}
