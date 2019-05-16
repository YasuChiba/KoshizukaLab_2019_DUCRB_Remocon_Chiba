

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

char buffer[3] = {' ',' ',' '};
int index = 0;
int digitPin = 9;

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

void allOff(int segment) {
  digitalWrite(D1, segment == D1 ? LOW : HIGH);
  digitalWrite(D2, segment == D2 ? LOW : HIGH);
  digitalWrite(D3, segment == D3 ? LOW : HIGH);
  digitalWrite(D4, segment == D4 ? LOW : HIGH);
  
  digitalWrite(pinLEDLeftDown, LOW);   
  digitalWrite(pinLEDBottom, LOW);   
  digitalWrite(pinLEDRightDown, LOW);   
  digitalWrite(pinLEDRightUp, LOW);   
  digitalWrite(pinLEDLeftUp, LOW);   
  digitalWrite(pinLEDTop, LOW);   
  digitalWrite(pinLEDCenter, LOW);   
}

void loop() {
  index = 0;
  while(Serial.available() > 0) {    
      buffer[index] = Serial.read();
      index += 1;
      if(index > 2) {
        break;
      }
  }

  for(int i = 0; i < 3; i++) {
    Serial.print(buffer[i]);
  }
  Serial.println();

  for(int i = 0; i < 3; i++) {
    digitPin = D3;
    if(i == 1) {
      digitPin = D2;
    } else if(i == 2) {
      digitPin = D1;
    } 

    if(buffer[i] == '0') {
      showZero(digitPin);
    } else if (buffer[i] == '1') {
      showOne(digitPin);
    } else if (buffer[i] == '2') {
      showTwo(digitPin);
    } else if (buffer[i] == '3') {
      showThree(digitPin);
    } else if (buffer[i] == '4') {
      showFour(digitPin);
    } else if (buffer[i] == '5') {
      showFive(digitPin);
    } else if (buffer[i] == '6') {
      showSix(digitPin);
    } else if (buffer[i] == '7') {
      showSeven(digitPin);
    } else if (buffer[i] == '8') {
      showEight(digitPin);
    } else if (buffer[i] == '9') {
      showNine(digitPin);
    } else {
      allOff(digitPin);
    }
    delay(5);
  }
}
