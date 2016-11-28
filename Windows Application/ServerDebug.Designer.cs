namespace lazerWin
{
    partial class ServerDebug
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.glbDebug = new System.Windows.Forms.CheckBox();
            this.udpDebug = new System.Windows.Forms.CheckBox();
            this.i2cDebug = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // glbDebug
            // 
            this.glbDebug.AutoSize = true;
            this.glbDebug.Location = new System.Drawing.Point(92, 147);
            this.glbDebug.Name = "glbDebug";
            this.glbDebug.Size = new System.Drawing.Size(91, 17);
            this.glbDebug.TabIndex = 0;
            this.glbDebug.Text = "Global Debug";
            this.glbDebug.UseVisualStyleBackColor = true;
            this.glbDebug.CheckedChanged += new System.EventHandler(this.glbDebug_CheckedChanged);
            // 
            // udpDebug
            // 
            this.udpDebug.AutoSize = true;
            this.udpDebug.Location = new System.Drawing.Point(92, 170);
            this.udpDebug.Name = "udpDebug";
            this.udpDebug.Size = new System.Drawing.Size(84, 17);
            this.udpDebug.TabIndex = 1;
            this.udpDebug.Text = "UDP Debug";
            this.udpDebug.UseVisualStyleBackColor = true;
            this.udpDebug.CheckedChanged += new System.EventHandler(this.udpDebug_CheckedChanged);
            // 
            // i2cDebug
            // 
            this.i2cDebug.AutoSize = true;
            this.i2cDebug.Location = new System.Drawing.Point(92, 193);
            this.i2cDebug.Name = "i2cDebug";
            this.i2cDebug.Size = new System.Drawing.Size(74, 17);
            this.i2cDebug.TabIndex = 2;
            this.i2cDebug.Text = "I2CDebug";
            this.i2cDebug.UseVisualStyleBackColor = true;
            this.i2cDebug.CheckedChanged += new System.EventHandler(this.i2cDebug_CheckedChanged);
            // 
            // ServerDebug
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(278, 224);
            this.Controls.Add(this.i2cDebug);
            this.Controls.Add(this.udpDebug);
            this.Controls.Add(this.glbDebug);
            this.Name = "ServerDebug";
            this.Text = "Server Debugging Console";
            this.TopMost = true;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox glbDebug;
        private System.Windows.Forms.CheckBox udpDebug;
        private System.Windows.Forms.CheckBox i2cDebug;


    }
}