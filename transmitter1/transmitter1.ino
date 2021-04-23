#include <iarduino_RF433_Transmitter.h>
#include <GyverButton.h>
#include "GyverEncoder.h"
GButton bt1(12);
GButton bt2(11);
GButton bt3(10);
GButton bt4(9);
GButton bt5(8);
GButton bt6(7);
iarduino_RF433_Transmitter radioTX(3);
int                     i[1] = {0};
int                     j[1] = {1};
int                     f[1] = {2};
int                     l[1] = {3};
int                     o[1] = {4};
int                     p[1] = {5};
int                     y[1] = {6};
int                     z[1] = {7};
int                     x[1] = {8};
int                     u[1] = {9};
int                     r[2] = {10};
int                     t[2] = {11};

uint8_t                  k;
Encoder enc(6, 5, 4, TYPE2);
void setup() {
  Serial.begin(9600);
  radioTX.begin(1000);
  radioTX.openWritingPipe(5);
  bt1.setDebounce(80);
  bt2.setDebounce(80);


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

  }
  if (bt2.isClick()) {
    radioTX.write(&j, sizeof(j));
  }
  if (enc.isRight()) {
    radioTX.write(&y, sizeof(y));
  }
  if (enc.isLeft()) {
    radioTX.write(&z, sizeof(z));
  }
  if (bt3.isClick()) {
    radioTX.write(&f, sizeof(f));
  }
  if (bt4.isClick()) {
    radioTX.write(&l, sizeof(l));
  }
  if (bt5.isClick()) {
    radioTX.write(&o, sizeof(o));
  }
  if (bt6.isClick()) {
    radioTX.write(&p, sizeof(p));
  }
  if (enc.isClick()) {
    radioTX.write(&x, sizeof(x));
  }
  if (enc.isRightH()) {
    radioTX.write(&u, sizeof(u));
  }
  if (enc.isLeftH()) {
    radioTX.write(&r, sizeof(r));
  }
}
