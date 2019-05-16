

int pinLEDLeftDown= 2;
int pinLEDBottom = 3;
int pinLEDRightDown = 4;
int pinLEDRightUp = 5;
int pinLEDLeftUp = 6;
int pinLEDTop = 7;
int pinLEDCenter = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

void setup() {          
  Serial.begin(9600);        
  pinMode(pinLEDLeftDown, OUTPUT);     
  pinMode(pinLEDBottom, OUTPUT);     
  pinMode(pinLEDRightDown, OUTPUT);     
  pinMode(pinLEDRightUp, OUTPUT);     
  pinMode(pinLEDLeftUp, OUTPUT);     
  pinMode(pinLEDTop, OUTPUT);     
  pinMode(pinLEDCenter, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
}

void showZero(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, HIGH);   
  digitalWrite(pinLEDBottom, HIGH);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, HIGH);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, LOW);   
}


void showOne(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, LOW);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, LOW);   
  digitalWrite(pinLEDTop, LOW);   
  digitalWrite(pinLEDCenter, LOW);   
}

void showTwo(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, HIGH);   
  digitalWrite(pinLEDBottom, HIGH);   
  digitalWrite(pinLEDRightDown, LOW);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, LOW);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void showThree(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, HIGH);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, LOW);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void showFour(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, LOW);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, HIGH);   
  digitalWrite(pinLEDTop, LOW);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void showFive(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, HIGH);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, LOW);   
  digitalWrite(pinLEDLeftUp, HIGH);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void showSix(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, HIGH);   
  digitalWrite(pinLEDBottom, HIGH);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, LOW);   
  digitalWrite(pinLEDLeftUp, HIGH);   
  digitalWrite(pinLEDTop, LOW);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void showSeven(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, LOW);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, LOW);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, LOW);   
}


void showEight(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, HIGH);   
  digitalWrite(pinLEDBottom, HIGH);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, HIGH);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void showNine(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, LOW);   
  digitalWrite(pinLEDRightDown, HIGH);   
  digitalWrite(pinLEDRightUp, HIGH);   
  digitalWrite(pinLEDLeftUp, HIGH);   
  digitalWrite(pinLEDTop, HIGH);   
  digitalWrite(pinLEDCenter, HIGH);   
}

void loop() {
  char tmp;
  if(Serial.available() > 0) {
    while(Serial.available() > 0) {    
      tmp = Serial.read();
      Serial.println(tmp);
    }
  }
  showZero(D1);
  delay(1);
  showOne(D2);
  delay(1);
  showTwo(D3);
  delay(1);
  showThree(D4);
  delay(1);
}
