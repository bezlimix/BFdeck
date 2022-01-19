#include <GyverButton.h>
#include <microLED.h>
#include "Parser.h"
//=======================КОНФИГУРАЦИЯ=======================//
#define backlight 1          //наличин подсветки 1-есть,0-нету
#define wireless 0           //наличие модуля bluetooth 1-есть,0-нету
#define deck_length 3        //кол-во клавиш в длинну               ⫷------------⌉
#define deck_wight 2         //кол-во клавиш в ширину               ⫷------------|
const int MAX_LEVEL = 100;   //максимальный уровень для Simon`s Says              |
const int NUM_LEDS = 6;      //это кол-во светодиодов (состоит из длинны*шарину)__⌋
//==========================================================//
GButton but1(2);             //инициализация каждой кнопки
GButton but2(3);             //инициализация каждой кнопки
GButton but3(4);             //инициализация каждой кнопки
GButton but4(5);             //инициализация каждой кнопки
GButton but5(6);             //инициализация каждой кнопки
GButton but6(7);             //инициализация каждой кнопки
microLED<6, A0, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip; //инициализация ленты(подсвектки)
void setup() {
 Serial.begin(9600);             //инициализация serial для общения через com-port
  but1.setTickMode(AUTO);        //настройка анти-дребезга для кнопки
  but2.setTickMode(AUTO);        //настройка анти-дребезга для кнопки
  but3.setTickMode(AUTO);        //настройка анти-дребезга для кнопки
  but4.setTickMode(AUTO);        //настройка анти-дребезга для кнопки
  but5.setTickMode(AUTO);        //настройка анти-дребезга для кнопки
  but6.setTickMode(AUTO);        //настройка анти-дребезга для кнопки
  for(int i = 0; i < deck_length; i++){  //
    int u = 0;                           //
    rainm[i] = u;                        //функция для настройки радуги(требуется для коректной работы радуги на любой длинне устр-ва) 
    u = u + 150;                         //
  }                                      //          
}                       

void loop() {
  uint32_t now = millis(); //создает таймер который позволит выполнять функции почти без задержки
  
//===================двух сторонее общение МК с ПК через протакол===================//  
  if (Serial.available()) {
    for (int u = 0; u < 50; u++) {
      ints[u] = 0;
    }
    char buf[255];
    for (int u = 0; u < 255; u++) {
      buf[u] = 0;
    }
    Serial.readBytesUntil('\n', buf, 255);
    Parser data(buf, ',');
    data.parseInts(ints);
   // for (int u = 0; u < 50; u++) {      //код отладки для проверки получаемых данных                 
   //   Serial.print(ints[u]);            //код отладки для проверки получаемых данных           
   //   Serial.print(",");                //код отладки для проверки получаемых данных       
   // }                                   //код отладки для проверки получаемых данных           
    switch (ints[0]) {
      case 0:{
        led_mode = ints[1];
        bright_flag = false;
        break;}
      case 1:{
        periodMs = ints[1];
        break;}
      case 2:
        {bright = ints[1];
        break;}
      case 3:
        {RGB[0] = ints[1];
        RGB[1] = ints[2];
        RGB[2] = ints[3];
        break;}
      case 4:
        {int n = 1;
        for (int x = 0; x < NUM_LEDS; x++) {
          for (int y = 0; y < 3; y++) {
            color_set[x][y] = ints[n];
            n++;
          }
        }
        break;}
      case 10:
        {Serial.print(deck_length);
        Serial.print(",");
        Serial.print(deck_wight);
        Serial.print(",");
        Serial.print(backlight);
        Serial.print(",");
        Serial.println(wireless);
        break;}
    }
  };
//==================================================================================//

//===================смена режима подсветки если она пристутствует(удалить блок при не надобности)===================//  
  if (now - lastTime > periodMs) {
    lastTime = now;
    switch (led_mode) {
      case 0:
        rainbow();
        break;
      case 1:
        rainbow2();
        break;
      case 2:
        temp();
        break;
      case 3:
        blinking();
        break;
      case 4:
        fill();
        break;
      case 5:
        RGBchange();
        break;
      case 10:
        Simon_loop();
        break;
    }
  };
//===================================================================================================================//

//==========================Код проверки нажатия кнопки(маштабировать при изменении кол-ва)==========================//
  if (but1.isClick()) {
    Serial.println("clk1");
  };
  if (but2.isClick()) {
    Serial.println("clk2");
  };
  if (but3.isClick()) {
    Serial.println("clk3");
  };
  if (but4.isClick()) {
    Serial.println("clk4");
  };
  if (but5.isClick()) {
    Serial.println("clk5");
  };
  if (but6.isClick()) {
    Serial.println("clk6");
  };
}
//===================================================================================================================//
}

//сюда вставлять функции подсветки
