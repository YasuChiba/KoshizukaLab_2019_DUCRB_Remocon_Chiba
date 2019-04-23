
int irPIN = 3;

void setup()
{
  //DDRD = B00001000; //PIN3をoutputに
  pinMode(3,OUTPUT);
  //PORTD = B11111111;
}

void ledOn() {
  PORTD = B00000001; //PIN3をHIGHに
  delayMicroseconds(9);
  PORTD = B00000000; //全PINをLOWに
  delayMicroseconds(17);
}

void loop() 
{
 
  /*
  while(1) {
    PORTD = B00000001; //PIN3をHIGHに
    delayMicroseconds(8);
    PORTD = B00000000; //全PINをLOWに
    delayMicroseconds(15);
  }
  */
  for(int i = 0; i < 10000000; i++) {
    PORTD = B00000001; //PIN3をHIGHに
    delayMicroseconds(8);
    PORTD = B00000000; //全PINをLOWに
    delayMicroseconds(15);
  }
  
}
