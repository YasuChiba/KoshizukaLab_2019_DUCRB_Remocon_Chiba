

#include <avr/io.h>
#define PWMPin 10
int buffer[33];

//詳細はever note 参照
void setup() {
  pinMode(PWMPin, OUTPUT);
  TCCR1A=0b00100010;
  TCCR1B=0b00011001;
  ICR1=420;
  OCR1A=210;
  off();
  Serial.begin(9600);
}

void on() {
  TCCR1B=0b00011001;
}

void off() {
  TCCR1B=0b00000000;
}

void startSignal() {
  on();
  delay(100);
  off();
  delay(100);
}

void endSignal() {
  on();
  delay(100);
  off();
  delay(50);
  on();
  delay(50);
  off();
}

void one() {
  on();
  delay(20);
  off();
  delay(20);
}

void zero() {
  on();
  delay(20);
  off();
  delay(10);
}

void readAllData() {
  int index = 0;
  while(Serial.available() > 0) {    
    buffer[index] = Serial.read();
    index++;
  }
}

void sendTest() {
  startSignal();
  one();
  zero();
  zero();
  zero();
  zero();
  one();
  zero();
  one();
  zero();
  endSignal();
  delay(1000);
}

void loop() {
  
  if(Serial.available()) {
    readAllData();
    /*
    String str = Serial.readStringUntil(';');
    if(str == "01") {
      sendTest();
    } 
    */
    if(buffer[0] == '0' && buffer[1] == '1') {
      sendTest();
    }
  }
  
  
}
