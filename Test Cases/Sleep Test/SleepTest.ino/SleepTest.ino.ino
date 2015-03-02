//The Globals
int buttonPressed;

void setup() {
  pinMode(13, OUTPUT);  
  pinMode(7, INPUT);
}

void loop() {
    //Check the input and update
  
    if(digitalRead(7) == LOW){
      buttonPressed = abs(1-buttonPressed);
    }

    //Send the LED on or off
    if(buttonPressed == 0)
      digitalWrite(13, HIGH);
    else
      digitalWrite(13, LOW);
      
    delay(200);
}
