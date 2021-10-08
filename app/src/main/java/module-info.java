module bf.app {
    requires javafx.controls;
    requires javafx.fxml;


    opens bf.app to javafx.fxml;
    exports bf.app;
}