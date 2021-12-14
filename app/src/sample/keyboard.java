package sample;

import java.awt.AWTException;
import java.awt.Robot;

import java.awt.event.KeyEvent;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import static sample.user_config.user_set;

public class keyboard {
    public static int sheet_now = 0;
    static String[] command_text = new String[6];
    static int[][] button_commands = new int[6][10];
    static int[] count_commands = new int[6];
    public static Map<String, Integer> buttons = new HashMap<String, Integer>();

    public static void fill() {
        buttons.put("a", KeyEvent.VK_A);
        buttons.put("b", KeyEvent.VK_B);
        buttons.put("c", KeyEvent.VK_C);
        buttons.put("d", KeyEvent.VK_D);
        buttons.put("e", KeyEvent.VK_E);
        buttons.put("f", KeyEvent.VK_F);
        buttons.put("g", KeyEvent.VK_G);
        buttons.put("h", KeyEvent.VK_H);
        buttons.put("i", KeyEvent.VK_I);
        buttons.put("j", KeyEvent.VK_J);
        buttons.put("k", KeyEvent.VK_K);
        buttons.put("l", KeyEvent.VK_L);
        buttons.put("m", KeyEvent.VK_M);
        buttons.put("n", KeyEvent.VK_N);
        buttons.put("o", KeyEvent.VK_O);
        buttons.put("p", KeyEvent.VK_P);
        buttons.put("q", KeyEvent.VK_Q);
        buttons.put("r", KeyEvent.VK_R);
        buttons.put("s", KeyEvent.VK_S);
        buttons.put("t", KeyEvent.VK_T);
        buttons.put("u", KeyEvent.VK_U);
        buttons.put("v", KeyEvent.VK_V);
        buttons.put("w", KeyEvent.VK_W);
        buttons.put("x", KeyEvent.VK_X);
        buttons.put("y", KeyEvent.VK_Y);
        buttons.put("z", KeyEvent.VK_Z);
        buttons.put("0", KeyEvent.VK_0);
        buttons.put("1", KeyEvent.VK_1);
        buttons.put("2", KeyEvent.VK_2);
        buttons.put("3", KeyEvent.VK_3);
        buttons.put("4", KeyEvent.VK_4);
        buttons.put("5", KeyEvent.VK_5);
        buttons.put("6", KeyEvent.VK_6);
        buttons.put("7", KeyEvent.VK_7);
        buttons.put("8", KeyEvent.VK_8);
        buttons.put("9", KeyEvent.VK_9);
        buttons.put("tab", KeyEvent.VK_TAB);
        buttons.put("f1", KeyEvent.VK_F1);
        buttons.put("f2", KeyEvent.VK_F2);
        buttons.put("f3", KeyEvent.VK_F3);
        buttons.put("f4", KeyEvent.VK_F4);
        buttons.put("f5", KeyEvent.VK_F5);
        buttons.put("f6", KeyEvent.VK_F6);
        buttons.put("f7", KeyEvent.VK_F7);
        buttons.put("f8", KeyEvent.VK_F8);
        buttons.put("f9", KeyEvent.VK_F9);
        buttons.put("f10", KeyEvent.VK_F10);
        buttons.put("f11", KeyEvent.VK_F11);
        buttons.put("f12", KeyEvent.VK_F12);
        buttons.put("f13", KeyEvent.VK_F13);
        buttons.put("f14", KeyEvent.VK_F14);
        buttons.put("f15", KeyEvent.VK_F15);
        buttons.put("f16", KeyEvent.VK_F16);
        buttons.put("f17", KeyEvent.VK_F17);
        buttons.put("f18", KeyEvent.VK_F18);
        buttons.put("ctrl", KeyEvent.VK_CONTROL);
        buttons.put("control", KeyEvent.VK_CONTROL);
        buttons.put("alt", KeyEvent.VK_ALT);
        buttons.put("option", KeyEvent.VK_ALT);
        buttons.put("shift", KeyEvent.VK_SHIFT);
        buttons.put("space", KeyEvent.VK_SPACE);
        buttons.put("esc", KeyEvent.VK_ESCAPE);
        buttons.put("enter", KeyEvent.VK_ENTER);
        buttons.put("backspace", KeyEvent.VK_BACK_SPACE);
        buttons.put("page_up", KeyEvent.VK_PAGE_UP);
        buttons.put("page_down", KeyEvent.VK_PAGE_DOWN);
        buttons.put("up", KeyEvent.VK_UP);
        buttons.put("down", KeyEvent.VK_DOWN);
        buttons.put("left", KeyEvent.VK_LEFT);
        buttons.put("right", KeyEvent.VK_RIGHT);
        buttons.put("win", KeyEvent.VK_WINDOWS);
        buttons.put(".", KeyEvent.VK_PERIOD);
        buttons.put(",", KeyEvent.VK_COMMA);
        buttons.put("/", KeyEvent.VK_SLASH);
        buttons.put(";", KeyEvent.VK_SEMICOLON);
        buttons.put("\\", KeyEvent.VK_BACK_SLASH);
        buttons.put("delete", KeyEvent.VK_DELETE);
        buttons.put("[", KeyEvent.VK_OPEN_BRACKET);
        buttons.put("]", KeyEvent.VK_CLOSE_BRACKET);
        buttons.put("play", KeyEvent.VK_PAUSE);
        buttons.put("cmd", KeyEvent.VK_META);
        buttons.put("caps", KeyEvent.VK_CAPS_LOCK);
        buttons.put("lclk", 1);
        buttons.put("rclk", 2);
    }

    public static Robot robot;

    static {
        try {
            robot = new Robot();
        } catch (AWTException e) {
            e.printStackTrace();
        }
    }

    public static void combination(int b, int a) {
        if (a != -1) {
            robot.keyPress(button_commands[b][a]);
            combination(b, a - 1);
            robot.keyRelease(button_commands[b][a]);
        }
    }

    public static void switch_button(String a) {
        int k;
        switch (a) {
            case "clk1":
                k = count_commands[0];
                combination(0, k);
                break;
            case "clk2":
                k = count_commands[1];
                combination(1, k);
                break;
            case "clk3":
                k = count_commands[2];
                combination(2, k);
                break;
            case "clk4":
                k = count_commands[3];
                combination(3, k);
                break;
            case "clk5":
                k = count_commands[4];
                combination(4, k);
                break;
            case "clk6":
                k = count_commands[5];
                combination(5, k);
                break;
        }

    }

    public static void init_from_excel(int a) {
        String[] s1 = command_text[a].split(" ");
        if (command_text[a].length() > 0) {
            count_commands[a] = s1.length - 1;
            for (int i = count_commands[a]; i > -1; i--) {
                button_commands[a][i] = buttons.get(s1[count_commands[a] - i]);
            }
        }
    }

    public static void initialisation(int a) throws IOException {
        String[] s1 = command_text[a].split(" ");
        if (command_text[a].length() > 0) {
            count_commands[a] = s1.length - 1;
            for (int i = count_commands[a]; i > -1; i--) {
                try {
                    button_commands[a][i] = buttons.get(s1[count_commands[a] - i]);
                } catch (Exception e) {
                    count_commands[a] = -1;
                    command_text[a] = "";
                }
            }
        } else
            count_commands[a] = -1;
        user_set(sheet_now, a);
    }
}
