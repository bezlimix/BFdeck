#include <GyverButton.h>
#include <Keyboard.h>
GButton but1(2);
GButton but2(3);
GButton but3(4);
GButton but4(5);
GButton but5(6);
GButton but6(7);

void setup() {
  Serial.begin(9600);
  but1.setTickMode(300);
  but2.setTickMode(200);
  but3.setTickMode(100);
  but4.setTickMode(100);
  but5.setTickMode(AUTO);
  but6.setTickMode(AUTO); 
}
void loop() {
  if (but1.isClick()) {Serial.println("clk1"); keyboard.press('F13');  
  };
  if (but2.isClick()) {Serial.println("clk2"); keyboard.press('F14'); 
  };
  if (but3.isClick()) {Serial.println("clk3"); keyboard.press('F15');
  };
  if (but4.isClick()) {Serial.println("clk4"); keyboard.press('F16');
  };  
  if (but5.isClick()) {Serial.println("clk5"); keyboard.press('F17');
  };
  if (but6.isClick()) {Serial.println("clk6"); keyboard.press('F18');
  };
  
 }
 
