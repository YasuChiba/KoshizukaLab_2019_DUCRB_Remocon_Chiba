

#include <avr/io.h>
#define PWMPin 10
#define testPin 9

//詳細はever note 参照
void setup() {
  pinMode(PWMPin, OUTPUT);
  pinMode(testPin, OUTPUT);

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

void readAllData(char* buffer) {
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

void dec2bin(int n, int digit, int* result)
{
    int mask;
    int i = 0;
    for(mask=(0x1<<(digit-1)); mask>0; mask>>=1){
        result[i] = mask & n ?1 : 0;
        i++;
    }
}

int* parseBuffer(char *buffer, int *result) {
   char tmp[10] = {'\0'};

   tmp[0] = buffer[0];
   tmp[1] = '\0';
   result[0] = atoi(tmp);
   tmp[0] = buffer[1];
   tmp[1] = '\0';
   result[1] = atoi(tmp);

   dec2bin(atoi(buffer+2),9,result+2);
}

void sendSequence(int* seq,int len) {
  startSignal();
  for(int i = 0; i < len; i++) {
    if(seq[i] == 0) {
      zero();
    } else {
      one();
    }
  }
  endSignal();
}

void loop() {
  int seq[11] = {0};
  char buffer[30] = {'\0'};
  /*
   buffer[0] = '0';
   buffer[1] = '1';
   buffer[2] = '3';
   buffer[3] = '0';
   buffer[4] = '5';
   parseBuffer(buffer, seq);
   Serial.println(buffer);
   for(int i = 0; i < 11; i++) {
       Serial.print(seq[i]);

   }
   
   Serial.println("");
   Serial.println("");
  delay(3000);
*/    
  
  if(Serial.available()) {
    digitalWrite(testPin, HIGH);
    readAllData(buffer);
    parseBuffer(buffer, seq);
    sendSequence(seq, 11);   
    digitalWrite(testPin, LOW);

  }  
  
}
