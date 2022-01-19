void rainbow() {                 //      
  strip.fill(mWheel(rain));      //                 
  rain++;                        //                      
  if (rain == 1530) {            //обычная радуга (все светодиоды меняют цвет)           
    rain = 0;                    //   
  }                              //                
  strip.show();                  //     
}                                //      



void rainbow2() {                      //                                                                      
  strip.set(0, mWheel(rainm[0]));      //                 
  strip.set(3, mWheel(rainm[0]));      //                 
  strip.set(1, mWheel(rainm[1]));      //                 
  strip.set(4, mWheel(rainm[1]));      //                 
  strip.set(2, mWheel(rainm[2]));      //                 
  strip.set(5, mWheel(rainm[2]));      //                 
  rainm[0]++;                          //                    
  rainm[1]++;                          //                    
  rainm[2]++;                          //                    
  if (rainm[0] == 1530) {              //радуга переливающяяся                                
    rainm[0] = 0;                      // 
  }                                    //          
  if (rainm[1] == 1530) {              //         
    rainm[1] = 0;                      // 
  }                                    //          
  if (rainm[2] == 1530) {              //         
    rainm[2] = 0;                      // 
  }                                    //          
  strip.show();                        //                      
}                                      //    



void temp() {                          //                    
  strip.fill(mKelvin(rain));           //                                   
  rain = rain + 10;                    //меняет цвет по температуре                           
  strip.show();                        //                      
}                                      //        

//=======мягкое зажигание и угасание цвета(цвет задан через протокол)=======//
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
//==========================================================================//

//мягкое зажигание и угасание цвета(цвет меняется по очереди красный,зеленый,синий)//
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
//=================================================================================//

//======заливка цветом (заданым каждому светодиоду по очереди через протокол)======//
void fill() {
  for (int x = 0; x < NUM_LEDS; x++) {
    strip.set(x, mRGB(color_set[x][0], color_set[x][1], color_set[x][2]));
  }

  strip.setBrightness(bright);
  strip.show();
}
//=================================================================================//

//===========================Игра Simon Says===========================//
void Simon_loop() {
  if (but1.isHold() && but4.isHold()) {
    led_mode = 0;
    loop();
  }
  if (level == 1) {
    level++;
    generate_sequence();
  }
  if (level != 1) {
    show_sequence();  
    get_sequence();   
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
  int flag = 0;  

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
  velocity -= 50;  
}
//=====================================================================//