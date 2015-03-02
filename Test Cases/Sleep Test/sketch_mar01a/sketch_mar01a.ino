#include <arduino.h>

int sensorValue;
float voltage;

void setup() {
 Serial.begin(9600);
 
 pinMode(A1, INPUT);
 pinMode(3, OUTPUT);
}
void loop() {
  
  sensorValue = 0;
  sensorValue = analogRead(A1);
  voltage = sensorValue * (5.0 / 1023.0);
  Serial.print("The sensor value is: ");
  Serial.print(sensorValue);
  Serial.print("\r\n"); 
  
  if(sensorValue >= 300) {
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }

  delay(100);  
}

