package sample;


import jssc.SerialPortException;
import jssc.SerialPortList;
import javafx.collections.FXCollections;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.scene.control.*;

import javafx.event.ActionEvent;
    import java.io.IOException;

public class Controller {
    @FXML
    private ToggleButton button1_field;

    @FXML
    private ToggleButton button2_field;

    @FXML
    private ToggleButton button3_field;

    @FXML
    private ToggleButton button4_field;

    @FXML
    private ToggleButton button5_field;

    @FXML
    private ToggleButton button6_field;

    @FXML
    public Button ok;

    @FXML
    public TextField text_field;

    @FXML
    public ToggleGroup configs;

    @FXML
    public ToggleButton[] config = new ToggleButton[8];

    @FXML
    public ComboBox<String> box_field = new ComboBox<>();

    public static int r = -1, conf_now = 0;
    public static ToggleGroup group = new ToggleGroup();

    @FXML
    public void initialize() {
        button1_field.setToggleGroup(group);
        button2_field.setToggleGroup(group);
        button3_field.setToggleGroup(group);
        button4_field.setToggleGroup(group);
        button5_field.setToggleGroup(group);
        button6_field.setToggleGroup(group);
        System.out.println("chupapi");
    }

    private void set_ports() {
        String[] portNames = SerialPortList.getPortNames();
        box_field.getItems().setAll(FXCollections.observableArrayList(portNames));
    }

    @FXML
    void accept(ActionEvent event) throws IOException {
        keyboard.command_text[r] = text_field.getText();
        keyboard.initialisation(r);
        if (keyboard.count_commands[r] != -1) {
            activated_button(r, 1);
        }
        else {
            activated_button(r, 0);
        }
    }

    @FXML
    public void click1(ActionEvent actionEvent) {
        if (r != 0) {
            r = 0;
            text_field.setVisible(true);
            ok.setVisible(true);
            text_field.setText(keyboard.command_text[0]);
        } else {
            r = -1;
            text_field.setVisible(false);
            ok.setVisible(false);
        }
    }

    @FXML
    public void click2(ActionEvent actionEvent) {
        if (r != 1) {
            r = 1;
            text_field.setVisible(true);
            ok.setVisible(true);
            text_field.setText(keyboard.command_text[1]);
        } else {
            r = -1;
            text_field.setVisible(false);
            ok.setVisible(false);
        }
    }

    @FXML
    public void click3(ActionEvent actionEvent) {
        if (r != 2) {
            r = 2;
            text_field.setVisible(true);
            ok.setVisible(true);
            text_field.setText(keyboard.command_text[2]);
        } else {
            r = -1;
            text_field.setVisible(false);
            ok.setVisible(false);
        }
    }

    @FXML
    public void click4(ActionEvent actionEvent) {
        if (r != 3) {
            r = 3;
            text_field.setVisible(true);
            ok.setVisible(true);
            text_field.setText(keyboard.command_text[3]);
        } else {
            r = -1;
            text_field.setVisible(false);
            ok.setVisible(false);
        }
    }

    @FXML
    public void click5(ActionEvent actionEvent) {
        if (r != 4) {
            r = 4;
            text_field.setVisible(true);
            ok.setVisible(true);
            text_field.setText(keyboard.command_text[4]);
        } else {
            r = -1;
            text_field.setVisible(false);
            ok.setVisible(false);
        }
    }

    @FXML
    public void click6(ActionEvent actionEvent) {
        if (r != 5) {
            r = 5;
            text_field.setVisible(true);
            ok.setVisible(true);
            text_field.setText(keyboard.command_text[5]);
        } else {
            r = -1;
            text_field.setVisible(false);
            ok.setVisible(false);
        }
    }

    public static String portName;
    @FXML
    public void selected_com(ActionEvent event) throws SerialPortException {
        portName = box_field.getValue();
        Jssc.initialize();
    }

    public void activated_button(int a, int b) {
        if(b == 1) {
            switch (a) {
                case 0:
                    button1_field.setStyle("-fx-background-color: #F0A500");
                    break;
                case 1:
                    button2_field.setStyle("-fx-background-color: #F0A500");
                    break;
                case 2:
                    button3_field.setStyle("-fx-background-color: #F0A500");
                    break;
                case 3:
                    button4_field.setStyle("-fx-background-color: #F0A500");
                    break;
                case 4:
                    button5_field.setStyle("-fx-background-color: #F0A500");
                    break;
                case 5:
                    button6_field.setStyle("-fx-background-color: #F0A500");
                    break;
            }
        }
        else {
            switch (a) {
                case 0:
                    button1_field.setStyle("-fx-background-color: #757575FF");
                    break;
                case 1:
                    button2_field.setStyle("-fx-background-color: #757575FF");
                    break;
                case 2:
                    button3_field.setStyle("-fx-background-color: #757575FF");
                    break;
                case 3:
                    button4_field.setStyle("-fx-background-color: #757575FF");
                    break;
                case 4:
                    button5_field.setStyle("-fx-background-color: #757575FF");
                    break;
                case 5:
                    button6_field.setStyle("-fx-background-color: #757575FF");
                    break;
            }
        }
    }

    @FXML
    public void update_com(Event event) {
        set_ports();
    }


}