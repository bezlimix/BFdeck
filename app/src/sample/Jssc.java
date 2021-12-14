package sample;

import jssc.*;

import java.util.Arrays;

public class Jssc {
    public static SerialPort serialPort;
    public static void initialize() throws SerialPortException {
        serialPort = new SerialPort(Controller.portName);
        try {
            System.out.println("kaef");
            serialPort.openPort();//Open serial port
            serialPort.setParams(9600, 8, 1, 0);
            int mask = SerialPort.MASK_RXCHAR + SerialPort.MASK_CTS + SerialPort.MASK_DSR;
            serialPort.setEventsMask(mask);//Set mask
            serialPort.addEventListener(new SerialPortReader());
        }
        catch (SerialPortException ex) {
            System.out.println(ex.toString());
        }
    }
    static class SerialPortReader implements SerialPortEventListener {

        public void serialEvent(SerialPortEvent event) {
            if(event.isRXCHAR()){//If data is available
                try {
                    String input = serialPort.readString();
                    try {
                        input = input.substring(0, 4);
                        System.out.println(input);
                        keyboard.switch_button(input);
                    }
                    catch (Exception e){}
                }
                catch (SerialPortException ex) {
                    System.out.println(ex.toString());
                }
            }
        }
    }
}
