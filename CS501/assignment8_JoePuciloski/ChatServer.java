/*
This program is an attempt at creating a Chat Server to host clients for the Final Project V
Author: Joseph Puciloski
Class: CS501 Assignment 8
Due: 5/16/18
*/
import java.util.ArrayList;
import java.util.Date;
import java.text.SimpleDateFormat;

import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.net.*;


public class ChatServer extends JFrame {

    private JTextArea jta = new JTextArea(); 
    private static int clientID = 0; 
    private ArrayList<HandleAClient> cList;
	private SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");

    public static void main(String[] args) {
        new ChatServer();
        System.exit(0);
    }

    public ChatServer() {
        //Chat GUI
        setLayout(new BorderLayout());
        jta.setEditable(false);
        add(new JScrollPane(jta), BorderLayout.CENTER);
        setTitle(" Chat Server ");
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);

        //Initialize client list, start server
        cList = new ArrayList<HandleAClient>();
        start();
    }

    public void start() {
        try {
            ServerSocket serverSocket = new ServerSocket(50505);


            while (true) {
                Socket socket = serverSocket.accept();
                jta.append("Starting thread for new chat client\n");
                HandleAClient t = new HandleAClient(socket);
                cList.add(t);
                t.start();
            }
        } catch (IOException ex) {
            System.err.println(ex);
        }
    }

    //Publish messages from server to clients
    private synchronized void publish(String message) {
        String messageTS = dateFormat.format(new Date()) + " " + message + "\n";
        jta.append(messageTS);
        for (int i = cList.size(); --i >= 0;) {
            HandleAClient ct = cList.get(i);
            ct.sendMsg(messageTS);
        }
    }

    class HandleAClient extends Thread {

        Socket socket;
        ObjectInputStream in;
        ObjectOutputStream out;
        String username;
        int id;
        ChatMessage cm;

        HandleAClient(Socket socket) {
            this.socket = socket;
            id = clientID++;
            try {
                out = new ObjectOutputStream(socket.getOutputStream());
                in = new ObjectInputStream(socket.getInputStream());
                username = (String) in.readObject();
                jta.append(new Date() + " " + username + " connected\n");
            } catch (IOException | ClassNotFoundException e) {
                System.err.println(e);
            }
        }

        public void run() {
            while (true) {
                try {
                    cm = (ChatMessage) in.readObject();
                } catch (IOException | ClassNotFoundException e) {
                    System.err.println(e);
                }
                if (!cm.endConnection()) {
                    publish(username + ": " + cm.getMessage());
                } else {
                    break;
                }
            }
            publish(username + " has disconnected from the server.");
        }

        private void sendMsg(String msg) {
            try {
                out.writeObject(msg);
            } catch (IOException e) {
                System.err.println(e);
            }
        }
    }
}
