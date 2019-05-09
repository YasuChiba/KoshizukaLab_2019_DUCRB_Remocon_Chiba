

#define PWMPin 10

//詳細はever note 参照
void setup() {
  pinMode(PWMPin, OUTPUT);


/*
  TCCR1A=0b00100010;
  TCCR1B=0b00011001;
  
  ICR1=420;
  OCR1A=210;
  */

  
  unsigned int frq = 38000; // 周波数
  float duty = 0.5;  
  TCCR1A = 0b00100001;
  TCCR1B = 0b00010010;
 
  // TOP値指定
  OCR1A = (unsigned int)(1000000 / frq);
 
  // Duty比指定
  OCR1B = (unsigned int)(1000000 / frq * duty);
  
  off();
  
  Serial.begin(9600);
}

void on() {
 
  TCCR1A = 0b00100001;
  TCCR1B = 0b00010010;
  
}

void off() {
  digitalWrite(PWMPin, LOW);
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
  /*
  digitalWrite(testPin, HIGH);
  delay(1000);
    digitalWrite(testPin, LOW);
      delay(1000);
      */
   
  
  int seq[11] = {0};
  char buffer[30] = {'\0'};
  
  if(Serial.available()) {
    readAllData(buffer);
    parseBuffer(buffer, seq);
    sendSequence(seq, 11);   
  }  
  
  
}
