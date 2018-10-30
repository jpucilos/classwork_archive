import java.io.*;
import java.net.*;

public class Homework3 {
	
	public static int port = 6666;
	public static InetAddress address;
	
	public static void main (String args[]){
				
		try {
			address = InetAddress.getByName("155.246.66.150");
			DatagramSocket socket = new DatagramSocket();
			String data = new String("Hello from Joseph Puciloski");
			byte[] buf = new byte[1000];
			DatagramPacket in = new DatagramPacket(buf, buf.length);
			
			buf = data.getBytes();		
			DatagramPacket out = new DatagramPacket(buf, buf.length, address, port);
			
			socket.send(out);
			System.out.println("Message Sent: " + new String(buf, "UTF-8"));
			
			socket.receive(in);
			
			System.out.println("Message Received");
			
			System.out.println(new String(in.getData(), "UTF-8"));
		} catch(Exception e){ 
			System.out.println(e.getMessage()); 
		}
	}
}
