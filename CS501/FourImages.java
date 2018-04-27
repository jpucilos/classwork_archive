/*
This program is an attempt at solving exercise 14.1 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 7
Due: 4/28/18
*/

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.geometry.Insets;
import javafx.stage.Stage;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class FourImages extends Application {
	
	@Override // Override the start method in the Application class
	public void start(Stage primaryStage) {
		BorderPane pane = new BorderPane();
		
		pane.setTop(getHBox());
		pane.setBottom(getHBox2());

		Scene scene = new Scene(pane);
		primaryStage.setTitle("ShowImages"); // Set the stage title
		primaryStage.setScene(scene); // Place the scene in the stage
		primaryStage.show(); // Display the stage
	}
	
	private HBox getHBox() {
		HBox hBox = new HBox(15);
		hBox.setPadding(new Insets(15, 15, 15, 15));
		Image UnitedKingdom = new Image("http://www.cs.armstrong.edu/liang/image/uk.gif");
		hBox.getChildren().add(new ImageView(UnitedKingdom));
		Image Canada = new Image("http://www.cs.armstrong.edu/liang/image/ca.gif");
		hBox.getChildren().add(new ImageView(Canada));
		return hBox;
	}
	
	private HBox getHBox2() {
		HBox hBox = new HBox(15);
		hBox.setPadding(new Insets(15, 15, 15, 15));
		Image China = new Image("http://www.cs.armstrong.edu/liang/image/china.gif");
		hBox.getChildren().add(new ImageView(China));
		Image US = new Image("http://www.cs.armstrong.edu/liang/image/us.gif");
		hBox.getChildren().add(new ImageView(US));
		return hBox;
	}
}