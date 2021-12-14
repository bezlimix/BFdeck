package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Workbook;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Paths;
import java.util.Objects;

public class Main extends Application {
    public static String absolutePath;
    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("sample-3.fxml"));
        primaryStage.setTitle("BFDeck");
        Scene scene = new Scene(root, 700, 400);
        scene.getStylesheets().add("resources/button.css");
        primaryStage.setScene(scene);
        primaryStage.getIcons().add(new Image("/resources/icon.png"));
        primaryStage.setResizable(false);
        primaryStage.show();

    }

    public static void main(String[] args) throws IOException, URISyntaxException {
        keyboard.fill();
        user_config c = new user_config();
        c.config_fill();
        launch(args);
    }
}