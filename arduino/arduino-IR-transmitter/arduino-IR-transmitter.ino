

#include <avr/io.h>
#define PWMPin 10

//詳細はever note 参照

void setup() {
  pinMode(PWMPin, OUTPUT);
  TCCR1A=0b00100010;
  TCCR1B=0b00011001;
  ICR1=420;
  OCR1A=210;
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

void loop() {
  while(1) {
    startSignal();
    one();
    one();
    endSignal();
    delay(5000);
  }
}
