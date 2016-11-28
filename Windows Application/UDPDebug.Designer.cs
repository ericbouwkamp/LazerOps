namespace lazerWin
{
    partial class UDPDebug
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
            this.initUDP = new System.Windows.Forms.Button();
            this.deinitUDP = new System.Windows.Forms.Button();
            this.sendCmdVal = new System.Windows.Forms.NumericUpDown();
            this.sendDataVal = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.sendUDP = new System.Windows.Forms.Button();
            this.SendAndReceiveUDP = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.connectedIndicator = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.sendCmdVal)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sendDataVal)).BeginInit();
            this.SuspendLayout();
            // 
            // initUDP
            // 
            this.initUDP.Location = new System.Drawing.Point(90, 12);
            this.initUDP.Name = "initUDP";
            this.initUDP.Size = new System.Drawing.Size(107, 23);
            this.initUDP.TabIndex = 0;
            this.initUDP.Text = "Initialize UDP";
            this.initUDP.UseVisualStyleBackColor = true;
            this.initUDP.Click += new System.EventHandler(this.initUDP_Click);
            // 
            // deinitUDP
            // 
            this.deinitUDP.Enabled = false;
            this.deinitUDP.Location = new System.Drawing.Point(90, 41);
            this.deinitUDP.Name = "deinitUDP";
            this.deinitUDP.Size = new System.Drawing.Size(107, 23);
            this.deinitUDP.TabIndex = 2;
            this.deinitUDP.Text = "Deinitialize UDP";
            this.deinitUDP.UseVisualStyleBackColor = true;
            this.deinitUDP.Click += new System.EventHandler(this.deinitUDP_Click);
            // 
            // sendCmdVal
            // 
            this.sendCmdVal.Location = new System.Drawing.Point(191, 87);
            this.sendCmdVal.Maximum = new decimal(new int[] {
            -1,
            0,
            0,
            0});
            this.sendCmdVal.Name = "sendCmdVal";
            this.sendCmdVal.Size = new System.Drawing.Size(81, 20);
            this.sendCmdVal.TabIndex = 3;
            this.sendCmdVal.Value = new decimal(new int[] {
            -1,
            0,
            0,
            0});
            this.sendCmdVal.ValueChanged += new System.EventHandler(this.sendCmdVal_ValueChanged);
            // 
            // sendDataVal
            // 
            this.sendDataVal.Location = new System.Drawing.Point(191, 116);
            this.sendDataVal.Maximum = new decimal(new int[] {
            -1,
            0,
            0,
            0});
            this.sendDataVal.Name = "sendDataVal";
            this.sendDataVal.Size = new System.Drawing.Size(81, 20);
            this.sendDataVal.TabIndex = 4;
            this.sendDataVal.Value = new decimal(new int[] {
            -1,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(134, 90);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(54, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Command";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(146, 119);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Data";
            // 
            // sendUDP
            // 
            this.sendUDP.Enabled = false;
            this.sendUDP.Location = new System.Drawing.Point(12, 85);
            this.sendUDP.Name = "sendUDP";
            this.sendUDP.Size = new System.Drawing.Size(112, 23);
            this.sendUDP.TabIndex = 7;
            this.sendUDP.Text = "Send";
            this.sendUDP.UseVisualStyleBackColor = true;
            this.sendUDP.Click += new System.EventHandler(this.sendUDP_Click);
            // 
            // SendAndReceiveUDP
            // 
            this.SendAndReceiveUDP.Enabled = false;
            this.SendAndReceiveUDP.Location = new System.Drawing.Point(12, 114);
            this.SendAndReceiveUDP.Name = "SendAndReceiveUDP";
            this.SendAndReceiveUDP.Size = new System.Drawing.Size(112, 23);
            this.SendAndReceiveUDP.TabIndex = 8;
            this.SendAndReceiveUDP.Text = "Send and Receive";
            this.SendAndReceiveUDP.UseVisualStyleBackColor = true;
            this.SendAndReceiveUDP.Click += new System.EventHandler(this.SendAndReceiveUDP_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(153, 155);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(110, 20);
            this.textBox1.TabIndex = 9;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(153, 181);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(110, 20);
            this.textBox2.TabIndex = 10;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(31, 159);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(103, 13);
            this.label3.TabIndex = 11;
            this.label3.Text = "Received Command";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(40, 184);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(79, 13);
            this.label4.TabIndex = 12;
            this.label4.Text = "Received Data";
            // 
            // connectedIndicator
            // 
            this.connectedIndicator.AutoSize = true;
            this.connectedIndicator.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.connectedIndicator.ForeColor = System.Drawing.Color.Red;
            this.connectedIndicator.Location = new System.Drawing.Point(31, 214);
            this.connectedIndicator.Name = "connectedIndicator";
            this.connectedIndicator.Size = new System.Drawing.Size(224, 39);
            this.connectedIndicator.TabIndex = 13;
            this.connectedIndicator.Text = "Disconnected";
            this.connectedIndicator.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // UDPDebug
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.connectedIndicator);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.SendAndReceiveUDP);
            this.Controls.Add(this.sendUDP);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.sendDataVal);
            this.Controls.Add(this.sendCmdVal);
            this.Controls.Add(this.deinitUDP);
            this.Controls.Add(this.initUDP);
            this.MaximumSize = new System.Drawing.Size(300, 300);
            this.MinimumSize = new System.Drawing.Size(300, 300);
            this.Name = "UDPDebug";
            this.Text = "UDP Debugging Console";
            this.TopMost = true;
            ((System.ComponentModel.ISupportInitialize)(this.sendCmdVal)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sendDataVal)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button initUDP;
        private System.Windows.Forms.Button deinitUDP;
        private System.Windows.Forms.NumericUpDown sendCmdVal;
        private System.Windows.Forms.NumericUpDown sendDataVal;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button sendUDP;
        private System.Windows.Forms.Button SendAndReceiveUDP;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label connectedIndicator;
    }
}