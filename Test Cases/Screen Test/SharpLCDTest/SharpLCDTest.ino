#include "SharpMemoryLcd.h"

SHARPMEMORYLCD lcd;

void setup() {                
  Serial.begin(9600);
  lcd.LcdInitialize();
  lcd.LcdAllClearMode();
  lcd.LcdStartEXTC();
 
   // initialize digital pin 13 as an output.
  pinMode(8, OUTPUT); 
}

void loop() {
  
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500); // wait for a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(80000); 
 
  //lcd.setCursor(0,0);
  //lcd.print("HI EMILY!");
  lcd.invert()
    
}
