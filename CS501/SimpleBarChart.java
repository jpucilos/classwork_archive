/*
This program is an attempt at solving exercise 14.12 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 7
Due: 4/28/18
*/
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;
 
public class SimpleBarChart extends Application {
    @Override public void start(Stage stage) {
        stage.setTitle("Exercise 14.1");
        final CategoryAxis xAxis = new CategoryAxis();
        final NumberAxis yAxis = new NumberAxis();
        final BarChart<String,Number> bc = 
            new BarChart<String,Number>(xAxis,yAxis);
        bc.setTitle("Grade Breakdown");   
        yAxis.setLabel("Percent");
 
        XYChart.Series series1 = new XYChart.Series();
        series1.setName("Projects");       
        series1.getData().add(new XYChart.Data("Projects", 20));
        
        XYChart.Series series2 = new XYChart.Series();
        series2.setName("Final");
        series2.getData().add(new XYChart.Data("Final", 40));
        
        XYChart.Series series3 = new XYChart.Series();
        series3.setName("Midterms");
        series3.getData().add(new XYChart.Data("Midterms", 30));

        XYChart.Series series4 = new XYChart.Series();
        series4.setName("Quizzes");
        series4.getData().add(new XYChart.Data("Quizzes", 10));
        
        Scene scene  = new Scene(bc,800,600);
        bc.getData().addAll(series1, series2, series3, series4);
        stage.setScene(scene);
        stage.show();
    }
 
    public static void main(String[] args) {
        launch(args);
    }
}