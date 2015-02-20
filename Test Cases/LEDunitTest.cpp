/* LED bargraph test file
*  Author Clark Asher
*  2/20/14
*  establishes max delay for persistance of vision
*/




const int redledPin = 2;
const int yellowledPin =3;
const int blueledPin =4;
const int greenledPin =5;

void setup() {
  pinMode(redledPin, OUTPUT);
  pinMode(yellowledPin,OUTPUT);
  pinMode(blueledPin,OUTPUT);
  pinMode(greenledPin,OUTPUT);
}

void loop() {
  
  int x;
  int y =10;  // 1 led delay
  int z =5;   // 2 led delay
  int q = 3;  // 3 led delay
  int w = 2;  // 4 led delay
  
  
  for(x=0;x<100;x++){    // one led on
    digitalWrite(redledPin, HIGH);
    delay(y);
    digitalWrite(redledPin, LOW);
    delay(y);
  }
 
  for(x=0;x<100;x++){   // two led on
    digitalWrite(redledPin, HIGH);
    delay(z);
    digitalWrite(redledPin, LOW);
    delay(z);
    
    digitalWrite(yellowledPin, HIGH);
    delay(z);
    digitalWrite(yellowledPin, LOW);
    delay(z);
  }

  for(x=0;x<100;x++){   // three led on
    digitalWrite(redledPin, HIGH);
    delay(q);
    digitalWrite(redledPin, LOW);
    delay(q);
    
    digitalWrite(yellowledPin, HIGH);
    delay(q);
    digitalWrite(yellowledPin, LOW);
    delay(q);
    
    digitalWrite(blueledPin, HIGH);
    delay(q);
    digitalWrite(blueledPin, LOW);
    delay(q);
    
  }
  
  for(x=0;x<100;x++){   // four led on
    digitalWrite(redledPin, HIGH);
    delay(w);
    digitalWrite(redledPin, LOW);
    delay(w);
    
    digitalWrite(yellowledPin, HIGH);
    delay(w);
    digitalWrite(yellowledPin, LOW);
    delay(w);
    
    digitalWrite(blueledPin, HIGH);
    delay(w);
    digitalWrite(blueledPin, LOW);
    delay(w);  
    
    digitalWrite(greenledPin, HIGH);
    delay(w);
    digitalWrite(greenledPin, LOW);
    delay(w);  
  }
      
  
}