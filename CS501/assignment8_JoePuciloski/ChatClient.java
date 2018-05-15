/*
This program is an attempt at creating a Chat Client to communicate with other clients for the Final Project V
Author: Joseph Puciloski
Class: CS501 Assignment 8
Due: 5/16/18
*/


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;

public class ChatClient extends JFrame{
	private JTextField jtfn = new JTextField(); //Name field
	private JTextField jtf = new JTextField(); //Chat send field
	private JTextArea jta = new JTextArea(); //Chat message log
	
	//Create input/output/socket
	private ObjectOutputStream out; 
	private ObjectInputStream in;
	private Socket socket;
	
	//Client username
	private String username;
	
	public static void main(String[] args) 
        {
		new ChatClient();
	}
	
	
	public ChatClient() {
		//GUI
		JPanel pName = new JPanel();
		JPanel pInput = new JPanel();
		JPanel pChat = new JPanel();
		JPanel pTop = new JPanel();
		JButton connect = new JButton("Connect");
		JButton send = new JButton("   Send   ");
		
		//Name Field
		pName.setLayout(new BorderLayout());
		pName.add(new JLabel(" Name "), BorderLayout.WEST);
		pName.add(jtfn, BorderLayout.CENTER);
		pName.add(connect, BorderLayout.EAST);
		jtfn.setHorizontalAlignment(JTextField.LEFT);
		
		//Chat Field
		pInput.setLayout(new BorderLayout());
		pInput.add(new JLabel(" Enter Text "), BorderLayout.WEST);
		pInput.add(jtf, BorderLayout.CENTER);
		pInput.add(send, BorderLayout.EAST);
		jtf.setHorizontalAlignment(JTextField.LEFT);
		
		//Combining Name/Chat
		pTop.setLayout(new GridLayout(2,1));
		pTop.add(pName);
		pTop.add(pInput);
		
		//Chat Message Area
		pChat.setLayout(new BorderLayout());
		jta.setEditable(false);
		pChat.add(new JScrollPane(jta), BorderLayout.CENTER);
		
		//Final GUI
		setLayout(new BorderLayout());
		add(pTop, BorderLayout.NORTH);
		add(pChat, BorderLayout.CENTER);
		
		jtf.addActionListener(new ChatFieldListener());
		send.addActionListener(new ChatFieldListener());
		jtfn.addActionListener(new NameFieldListener());
		connect.addActionListener(new NameFieldListener());
		setTitle(" Chat Client ");
		setSize(500,300);
		//setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
                
                this.addWindowListener(ExitListener);
	}
	
	//Start chat client, connect to server
	public void start(){
		try {
			socket = new Socket("localhost", 50505);
			in = new ObjectInputStream(socket.getInputStream());
			out = new ObjectOutputStream(socket.getOutputStream());
		}
		catch (IOException ex)
                {
			System.err.println(ex);
                        System.exit(1);
		}
		jta.append("Connection accepted\n");
	
		new HandleServerClient().start();
		
		try
                {
			out.writeObject(username);
		}
		catch (IOException ex){
			System.err.println(ex);
		}
	}
              
	
	//Chat ActionListener
	private class ChatFieldListener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e){
			try {
				out.writeObject(new ChatMessage(jtf.getText()));
				jtf.setText("");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
		}
	}
        
	
	//Chat Username Listener
	private class NameFieldListener implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e){
			username = jtfn.getText();
			jtfn.setText(username);
			jtfn.setEditable(false);
			start();
		}
	}

        WindowListener ExitListener = new WindowAdapter()
        {
              @Override
              public void windowClosing(WindowEvent event)
              {
                try
                {
                    System.out.println("done");
                    out.writeObject(new ChatMessage());
                }
                catch(IOException e)
                {
                    e.printStackTrace();
                }
                System.exit(0);
              }
        };
	
	//Thread to handle server
	class HandleServerClient extends Thread{
		public void run(){
			while(true){
				try{
					String msg = (String) in.readObject();
					jta.append(msg);
				}
				catch (IOException | ClassNotFoundException e){
					System.err.println(e);
				}
			}
		}
	}
}
