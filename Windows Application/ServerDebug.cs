using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace lazerWin
{
    public partial class ServerDebug : Form
    {
        public ServerDebug()
        {
            InitializeComponent();
        }

        private void debugCheckBox_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void glbDebug_CheckedChanged(object sender, EventArgs e)
        {
            if (glbDebug.Checked == true)
            {
                UDP.send(769, 1);
                udpDebug.Enabled = false;
                i2cDebug.Enabled = false;
            }
            else
            {
                UDP.send(769, 0);
                udpDebug.Enabled = true;
                i2cDebug.Enabled = true;
            }
        }

        private void udpDebug_CheckedChanged(object sender, EventArgs e)
        {
            if (udpDebug.Checked == true)
            {
                UDP.send(770, 1);
            }
            else
            {
                glbDebug.Checked = false;
                UDP.send(770, 0);
            }
        }

        private void i2cDebug_CheckedChanged(object sender, EventArgs e)
        {
            if (i2cDebug.Checked == true)
            {
                UDP.send(771, 1);
            }
            else
            {
                glbDebug.Checked = false;
                UDP.send(771, 0);
            }
        }
    }
}
