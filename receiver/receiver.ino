
#include <Keyboard.h>
#include <iarduino_RF433_Receiver.h>
iarduino_RF433_Receiver    radioRX(2);
char                     i[] = "Egor is a boy";             // Создаём массив для передачи данных
char                     j[20]; // Создаём массив для приёма   данных
int el = 0;
uint8_t                  k;
void setup() {
  //  ===============================
  Serial.begin(9600);
  radioRX.begin(1000);                                  // Скорость приёма данных можно изменить вызвав данную функцию в любом месте кода. Параметры (i433_5KBPS, i433_4KBPS, i433_3KBPS, i433_2KBPS, i433_1KBPS, i433_500BPS, i433_100BPS), i433_1KBPS - 1кбит/сек
  radioRX.openReadingPipe (5);                          // Закрываем 2 трубу от  приёма данных (если вызвать функцию без параметра, то будут закрыты все трубы сразу, от 0 до 7)
  radioRX.startListening  ();
  Keyboard.begin();
}
void loop() {
  //  =============================== ПРИЁМНИК
  if (radioRX.available(&k)) {
    radioRX.read(&el, 1 );
    Serial.println(el);
    switch (el) {
      case 0:
        Keyboard.write(KEY_F13);
        break;
      case 1:
        Keyboard.write(KEY_F14);
        break;
      case 2:
        Keyboard.write(KEY_F15);
        break;
      case 3:
        Keyboard.write(KEY_F16);
        break;
      case 4:
        Keyboard.write(KEY_F17);
        break;
      case 5:
        Keyboard.write(KEY_F18);
        break;
      case 6:
        Keyboard.write(KEY_F19);
        break;
      case 7:
        Keyboard.write(KEY_F20);
        break;
      case 8:
        Keyboard.write(KEY_F21);
        break;
      case 9:
        Keyboard.write(KEY_F22);
        break;
      case 10:
        Keyboard.write(KEY_F23);
        break;
      case 11:
        Keyboard.write(KEY_F24);
        break;

    }


  }

}
