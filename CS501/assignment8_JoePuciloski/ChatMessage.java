/*
This program is an attempt at handling messaging for a chat server for the Final Project V
Author: Joseph Puciloski
Class: CS501 Assignment 8
Due: 5/16/18
*/
public class ChatMessage implements java.io.Serializable {
	private String message;
        private boolean shouldDisconnect;
	
	ChatMessage(String message){
		this.message = message;
                this.shouldDisconnect = false;
	}
        
        ChatMessage()
        {
            this.message = null;
            this.shouldDisconnect = true;
        }
	
	String getMessage(){
		return message;
	}

        boolean endConnection()
        {
            return shouldDisconnect;
        }
}
