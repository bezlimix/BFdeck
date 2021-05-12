#define EB_HOLD 100
#define EB_FAST 30
#define EB_CLICK 200
#include <iarduino_RF433_Transmitter.h>
#include <EncButton.h>
EncButton<EB_CALLBACK,5,6,4> enc;
EncButton<EB_CALLBACK,12> bt1;
EncButton<EB_CALLBACK,11> bt2;
EncButton<EB_CALLBACK,10> bt3;
EncButton<EB_CALLBACK,9> bt4;
EncButton<EB_CALLBACK,8> bt5;
EncButton<EB_CALLBACK,7> bt6;
iarduino_RF433_Transmitter radioTX(3);
int i[1] = {0};
int j[1] = {1};
int f[1] = {2};
int l[1] = {3};
int o[1] = {4};
int p[1] = {5};
int y[1] = {6};
int z[1] = {7};
int x[1] = {8};
int u[1] = {9};
int r[2] = {10};
int t[2] = {11};
uint8_t k;
void setup() {
  Serial.begin(9600);
  radioTX.begin(1000);
  radioTX.openWritingPipe(5);
}
void loop() {
  enc.tick();
  bt1.tick();
  bt2.tick();
  bt3.tick();
  bt4.tick();
  bt5.tick();
  bt6.tick();
  if (bt1.isClick()) {
    radioTX.write(&i, sizeof(i));
    Serial.println("bt1");
  }
  if (bt2.isClick()) {
    radioTX.write(&j, sizeof(j));
    Serial.println("bt2");
  }
  if (enc.isRight()) {
    radioTX.write(&y, sizeof(y));
    Serial.println("Right");
  }
  if (enc.isLeft()) {
    radioTX.write(&z, sizeof(z));
    Serial.println("Left");
  }
  if (bt3.isClick()) {
    radioTX.write(&f, sizeof(f));
    Serial.println("bt3");
  }
  if (bt4.isClick()) {
    radioTX.write(&l, sizeof(l));
    Serial.println("bt4");
  }
  if (bt5.isClick()) {
    radioTX.write(&o, sizeof(o));
    Serial.println("bt5");
  }
  if (bt6.isClick()) {
    radioTX.write(&p, sizeof(p));
    Serial.println("bt6");
  }
  if (enc.isClick()) {
    radioTX.write(&x, sizeof(x));
    Serial.println("Click");
  }
  if (enc.isRightH()) {
    radioTX.write(&u, sizeof(u));
    Serial.println("RightH");
  }
  if (enc.isLeftH()) {
    radioTX.write(&r, sizeof(r));
    Serial.println("LeftH");
  }
}
