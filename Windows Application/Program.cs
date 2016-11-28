using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;


namespace lazerWin
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            UDP.connect();
            Application.Run(new lazerWin());
           
        }
    }
}
