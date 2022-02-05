#include <GyverButton.h>
#include <microLED.h>
#include "Parser.h"
#include <EEPROM.h>
//=======================КОНФИГУРАЦИЯ=======================//
#define backlight 1          //наличин подсветки 1-есть,0-нету
#define wireless 0           //наличие модуля bluetooth 1-есть,0-нету
#define deck_length 3        //кол-во клавиш в длинну               ⫷------------⌉
#define deck_wight 2         //кол-во клавиш в ширину               ⫷------------|
const int MAX_LEVEL = 100;   //максимальный уровень для Simon`s Says              |
const int NUM_LEDS = 6;      //это кол-во светодиодов (состоит из длинны*шарину)__⌋
//==========================================================//
GButton but1(2);
GButton but2(3);
GButton but3(4);
GButton but4(5);
GButton but5(6);
GButton but6(7);
GButton buts[NUM_LEDS] = {but1,but2,but3,but4,but5,but6};
mData simon_color[4] = { mRed, mYellow, mAqua, mGreen };
int ints[50];
int sequence[MAX_LEVEL];
int your_sequence[MAX_LEVEL];
int velocity = 1000;
int level = 1;
uint8_t color_set[NUM_LEDS][3];
microLED<6, A0, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;
uint32_t lastTime = 0;
uint16_t periodMs = 10;
int rain = 0;
uint8_t RGB[3] = { 0, 0, 0 };
uint8_t changer_color = 0;
uint8_t bright = 255;
bool bright_flag = false;
unsigned char rainm[deck_length] = { 0, 30, 60};
void setup() {
  Serial.begin(9600);
  but1.setTickMode(AUTO);
  but2.setTickMode(AUTO);
  but3.setTickMode(AUTO);
  but4.setTickMode(AUTO);
  but5.setTickMode(AUTO);
  but6.setTickMode(AUTO);
}
void loop() {
  uint32_t now = millis();
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
    for (int u = 0; u < 50; u++) {
      Serial.print(ints[u]);
      Serial.print(",");
    }
    switch (ints[0]) {
      case 0:{
        EEPROM.write(0, ints[1]);
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
  if (now - lastTime > periodMs) {
    lastTime = now;
    switch (EEPROM.read(0)) {
      case 0:
        rainbow();
        break;
      case 1:
        transfusion();
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
void rainbow() {
  strip.fill(mWheel(rain));
  rain++;
  if (rain == 1530) {
    rain = 0;
  }
  strip.show();
}
void transfusion() {
  strip.set(0, mWheel8(rainm[0]));
  strip.set(3, mWheel8(rainm[0]));
  strip.set(1, mWheel8(rainm[1]));
  strip.set(4, mWheel8(rainm[1]));
  strip.set(2, mWheel8(rainm[2]));
  strip.set(5, mWheel8(rainm[2]));
  rainm[0]++;
  rainm[1]++;
  rainm[2]++;
  strip.show();
}
void temp() {
  strip.fill(mKelvin(rain));
  rain = rain + 10;
  strip.show();
}
void blinking() {
  strip.fill(mRGB(RGB[0], RGB[1], RGB[2]));
  strip.setBrightness(bright);
  if (bright_flag == true) {
    bright++;
  } else {
    bright--;
  }
  if (bright >= 255) {
    bright_flag = !bright_flag;
  }
  if (bright <= 0) {
    bright_flag = !bright_flag;
  }
  strip.show();
}
void RGBchange() {
  strip.show();
  strip.setBrightness(bright);
  switch (changer_color) {
    case 0:
      strip.fill(mRGB(255, 0, 0));
      break;
    case 1:
      strip.fill(mRGB(0, 255, 0));
      break;
    case 2:
      strip.fill(mRGB(0, 0, 255));
      break;
  }
  if (bright_flag == true) {
    bright++;
  } else {
    bright--;
  }
  if (bright >= 255) {
    bright_flag = !bright_flag;
  }
  if (bright <= 0) {
    bright_flag = !bright_flag;
    changer_color = changer_color + 1;
    if (changer_color >= 3) {
      changer_color = 0;
    }
  }
}
void fill() {
  for (int x = 0; x < NUM_LEDS; x++) {
    strip.set(x, mRGB(color_set[x][0], color_set[x][1], color_set[x][2]));
  }

  strip.setBrightness(bright);
  strip.show();
}
void Simon_loop() {
  if (but1.isHold() && but4.isHold()) {
    EEPROM.write(0, 0);
    loop();
  }
  if (level == 1) {
    level++;
    generate_sequence();
  }
  if (level != 1) {
    show_sequence();  //show the sequence
    get_sequence();   //wait for your sequence
  }
}
void show_sequence() {
  strip.clear();
  strip.show();
  for (int i = 0; i < level; i++) {
    strip.set(sequence[i], simon_color[i]);
    strip.show();
    delay(velocity);
    strip.set(sequence[i], mBlack);
    strip.show();
    delay(200);
  }
}
void get_sequence() {
  int flag = 0;  //this flag indicates if the sequence is correct

  for (int i = 0; i < level; i++) {
    flag = 0;
    while (flag == 0) {
      if (but2.isClick()) {
        strip.set(1, simon_color[0]);
        strip.show();
        your_sequence[i] = 1;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }
        strip.set(1, mRGB(000, 000, 000));
        strip.show();
      }

      if (but3.isClick()) {
        strip.set(2, simon_color[1]);
        strip.show();
        your_sequence[i] = 2;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }
        strip.set(2, mRGB(000, 000, 000));
        strip.show();
      }

      if (but5.isClick()) {
        strip.set(4, simon_color[2]);
        strip.show();
        your_sequence[i] = 4;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }
        strip.set(4, mRGB(000, 000, 000));
        strip.show();
      }

      if (but6.isClick()) {
        strip.set(5, simon_color[3]);
        strip.show();
        your_sequence[i] = 5;
        flag = 1;
        delay(200);
        if (your_sequence[i] != sequence[i]) {
          wrong_sequence();
          return;
        }
        strip.set(5, mRGB(000, 000, 000));
        strip.show();
      }
    }
  }
  right_sequence();
}
void generate_sequence() {
  randomSeed(millis());

  for (int i = 0; i < MAX_LEVEL; i++) {
    sequence[i] = random(0, 4);
  }
  for (int i = 0; i < MAX_LEVEL; i++) {
    switch (sequence[i]) {
      case 0:
        sequence[i] = 1;
        break;
      case 1:
        sequence[i] = 2;
        break;
      case 2:
        sequence[i] = 4;
        break;
      case 3:
        sequence[i] = 5;
        break;
    }
  }
}
void wrong_sequence() {
  for (int i = 0; i < 3; i++) {
    strip.fill(mRed);
    strip.show();
    delay(250);
    strip.fill(mBlack);
    strip.show();
    delay(250);
  }
  level = 1;
  velocity = 1000;
}
void right_sequence() {
  strip.clear();
  for (int i = 0; i < 3; i++) {
    strip.fill(mGreen);
    strip.show();
    delay(250);
    strip.fill(mBlack);
    strip.show();
    delay(250);
  }

  if (level < MAX_LEVEL)
    ;
  level++;
  velocity -= 50;  //increase difficulty
}