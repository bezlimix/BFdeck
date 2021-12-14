package sample;

import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import java.io.*;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Paths;
import java.util.Objects;

import static sample.Main.absolutePath;
import static sample.keyboard.*;

public class user_config {
    public static HSSFWorkbook wb;
    static HSSFSheet sheet;
    public static FileOutputStream fos;
    public void config_fill() throws IOException, URISyntaxException {
        getPath();
        System.out.println(absolutePath);
        Controller c = new Controller();
        fos = new FileOutputStream(absolutePath);
        wb = new HSSFWorkbook(new FileInputStream(absolutePath));
        sheet = wb.getSheetAt(0);
        for (int i = 0; i < 6; i++) {
            try {
                command_text[i] = sheet.getRow(0).getCell(i).getStringCellValue();
                System.out.println(command_text[i]);
            }catch (Exception ignored){}
            if (command_text[i] != null) {
                init_from_excel(i);
                c.activated_button(i, 1);
            }
        }
    }

    public void getPath() throws URISyntaxException {
        URL res = getClass().getClassLoader().getResource("resources/config.xlsx");
        File file = Paths.get(Objects.requireNonNull(res).toURI()).toFile();
        absolutePath = file.getAbsolutePath();
    }

    public static void user_get(int a) {
        for (int i = 0; i < 6; i++) {
            try {
                command_text[i] = sheet.getRow(a).getCell(i).getStringCellValue();
                System.out.println(command_text[i]);
                initialisation(i);
            }
            catch(Exception ignored){}
        }
    }

    public static void user_set(int row, int cell) throws IOException {
        sheet.createRow(row).createCell(cell).setCellValue(command_text[cell]);
        System.out.println(sheet.getRow(row).getCell(cell).getStringCellValue());
        wb.write(fos);
    }
}