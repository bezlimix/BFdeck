#include <GyverButton.h>
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
  if (but1.isClick()) {Serial.println("clk1");  
  };
  if (but2.isClick()) {Serial.println("clk2");  
  };
  if (but3.isClick()) {Serial.println("clk3"); 
  };
  if (but4.isClick()) {Serial.println("clk4"); 
  };  
  if (but5.isClick()) {Serial.println("clk5"); 
  };
  if (but6.isClick()) {Serial.println("clk6");
  };
  
 }
 
