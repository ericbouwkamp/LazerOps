using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Net;

namespace lazerWin
{
    public class UDP
    {
        private const string hostname = "192.168.1.200";
        private const int port = 5000;
        static UdpClient udp;
        public static bool connected = false;

        public static bool connect()
        {
            try
            {
                udp = new UdpClient(hostname, port);
                connected = true;
                return true;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                return false;
            }
        }

        public static bool disconnect()
        {
            try
            {
                udp.Close();
                connected = false;
                return true;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
                return false;
            }
        }

        public static void send(uint cmd, uint data)
        {
            Byte[] cmdBytes = BitConverter.GetBytes(cmd);
            Byte[] datBytes = BitConverter.GetBytes(data);
            Byte[] sendBytes = new Byte[8];
            Buffer.BlockCopy(datBytes, 0, sendBytes, 0, 4);
            Buffer.BlockCopy(cmdBytes, 0, sendBytes, 4, 4);
//            Console.WriteLine(Encoding.Default.GetString(sendBytes));
            if (BitConverter.IsLittleEndian)
                Array.Reverse(sendBytes);
                
            try
            {
                udp.Send(sendBytes, sendBytes.Length);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());   
            }
        }
        public static void receive(ref int cmd, ref int data)
        {
            try
            {
                IPEndPoint server = new IPEndPoint(IPAddress.Any, 0);
                byte[] received = new byte[1024];
                received = udp.Receive(ref server);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }


    }
}
