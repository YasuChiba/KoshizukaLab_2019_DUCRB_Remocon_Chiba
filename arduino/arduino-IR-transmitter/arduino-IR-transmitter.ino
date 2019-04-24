

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

void startSignal() {
  TCCR1B=0b00011001;
  delay(100);
  TCCR1B=0b00000000;
  delay(100);
}

void one() {
  TCCR1B=0b00011001;
  delay(20);
  TCCR1B=0b00000000;
  delay(20);
}

void zero() {
  TCCR1B=0b00011001;
  delay(20);
  TCCR1B=0b00000000;
  delay(10);
}

void loop() {
  while(1) {
    startSignal();
    one();
    one();
    zero();
    zero();
    one();
    zero();
    one();
    zero();
    startSignal();

    delay(2000);
  }
}
