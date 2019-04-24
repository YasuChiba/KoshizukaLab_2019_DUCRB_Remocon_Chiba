

#include <avr/io.h>
#define PWMPin 10
/*
void setup() {
  pinMode(PWMPin, OUTPUT);
  TCCR1A=0b00100001;
  TCCR1B=0b00010010;
  OCR1A = (unsigned int)(1000000 / 38000L);
  OCR1B=(unsigned int)(1000000 / 19000L)*0.5;
}

void loop() {
  
}
*/


unsigned int frq = 38000L; // 周波数
float duty = 0.5; // 指定したいデューティ比

void setup() {
  pinMode(PWMPin, OUTPUT);
   pinMode(9, OUTPUT);

   // モード指定
  TCCR1A = 0b10100001;
  TCCR1B = 0b00010010;

  // TOP値指定
  OCR1A = (unsigned int)(1000000 / frq);

  // Duty比指定
  OCR1B = (unsigned int)(1000000 / frq * duty);
}

void one() {
  TCCR1B = 0b00010010;
  delay(20);
  TCCR1B = 0b00000000;
  delay(20);
}

void zero() {
  TCCR1B = 0b00010010;
  delay(20);
  TCCR1B = 0b00000000;
  delay(10);
}

void loop() {
  TCCR1B = 0b00010010;
  delay(20);
  TCCR1B = 0b00000000;
  delay(20);
  TCCR1B = 0b00010010;

  while(1){
    //TCCR1B = 0b00010010;
    delay(10);
    //one();
  }
  
}
