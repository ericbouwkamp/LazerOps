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
    public partial class lazerWin : Form
    {
        public lazerWin()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void debugToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void uDPToolStripMenuItem_Click(object sender, EventArgs e)
        {
            UDPDebug udpDebug = new UDPDebug();
            udpDebug.Show();
        }

        private void serverToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ServerDebug sDebug = new ServerDebug();
            sDebug.Show();
        }
    }
}
