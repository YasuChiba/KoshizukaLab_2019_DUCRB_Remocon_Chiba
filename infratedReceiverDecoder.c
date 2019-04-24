#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>                                                             


#define INFRATED_RECEIVER_PIN 0

//Aが基準値。Bがテストされる
int isCloseEnough(int A, int B) {
  //printf("isCloseEnough %d  %d\n",A,B);
  if(A*0.9 <= B && B <= A*1.1) {
    return 1;
  }
  return 0;
}

void waitUntilStartSignal() {
  int value = 0;
  int prevValue = 0;
  int startTime = 0;
  int now = 0;
  int pulseLength = 0;

  int pulseLengthIs100 = 0;
  int _isCloseEnough = 0;

  while(1) {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if(value != prevValue) {
      now = millis();
      pulseLength = now - startTime;
      startTime = now;
      _isCloseEnough = isCloseEnough(100,pulseLength);
      if(_isCloseEnough == 1 && pulseLengthIs100 == 0) {
        pulseLengthIs100 = 1;
      } else if (_isCloseEnough == 1 && pulseLengthIs100 == 1) {
        return;
      } else {
        pulseLengthIs100 = 0;
      }
    }
    prevValue = value;
  }
}

void _decode(int pulseLength1, int pulseLength2) {
  printf("%d  %d\n",pulseLength1,pulseLength2);
}

void decode() {

  int value = 0;
  int prevValue = 0;

  int startTime = 0;
  int now = 0;
  int pulseLength1 = 0;
  int pulseLength2 = 0;

  while(1) {
    waitUntilStartSignal();
    startTime = millis();
    printf("\nStart  \n");


    while(1) {
      value = digitalRead(INFRATED_RECEIVER_PIN);
      if(value != prevValue) {
        now = millis();
        pulseLength1 = now - startTime;
        startTime = now;
        prevValue = value;
        while(1) {
          value = digitalRead(INFRATED_RECEIVER_PIN);
          if(value != prevValue) {
            now = millis();
            pulseLength2 = now - startTime;
            startTime = now;
            break;
          }
        }
        _decode(pulseLength1,pulseLength2);

      }
      prevValue = value;
    }
  }
}


void decodeTest2() {
  int value = 0;
  int prevValue = 0;
  int startTime = 0;
  int now = 0;
  int pulseLength = 0;

  int arrayLength = 1000;
  int array[arrayLength][2];
  int counter = 0;


  value = 1;

  while(1) {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if(value != prevValue) {
      now = millis();
      pulseLength = now - startTime;
      startTime = now;
      //printf("%d  %d  %d\n", prevValue, pulseLength, now);
      array[counter][0] = prevValue;
      array[counter][1] = pulseLength;
      array[counter][2] = now;
      counter++;
      if(counter >= arrayLength) {
        break;
      }
    }
    prevValue = value;

    //delayMicroseconds(100);
    //delay(10);    
  }

  for(int i = 0; i < arrayLength; i++) {
    if(array[i][0] == 0) {
      printf("%s  %d  \n", "ON", array[i][1]);
    } else {
      printf("%s  %d  \n", "OFF", array[i][1]);
    }
  }
}


void decodeTest3() {
  int value = 0;
  int prevValue = 0;
  int startTime = 0;
  int now = 0;
  int pulseLength = 0;

  value = 1;

  while(1) {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if(value != prevValue) {
      now = millis();
      pulseLength = now - startTime;
      startTime = now;
      printf("%d  %d  %d\n", prevValue, pulseLength, now);
    }
    prevValue = value;
  }
}

void toriaezuRead() {
  int value = 0;
  while(1) {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    printf("%d\n",value);
    delayMicroseconds(1);

  }
}

int main(int argc, char *argv[])
{
  wiringPiSetup();
  pinMode(INFRATED_RECEIVER_PIN, INPUT);
  pullUpDnControl(INFRATED_RECEIVER_PIN, PUD_UP);


  if(strcmp(argv[1],"toriaezu") == 0) {
    toriaezuRead();
  } else if(strcmp(argv[1], "decode2") == 0) {
    decodeTest2();
  } else if(strcmp(argv[1],"decode3") == 0) {
    decodeTest3();
  } else if(strcmp(argv[1], "decode") == 0) {
    decode();
  }

  //useCallback();
  //useDigitalRead(atoi(argv[1]), atoi(argv[2]));
  //printDigitalRead();
  //digitalReadTest();
  //decodeTest();
  //decodeTest2();
 // decodeTest3();
  //toriaezuRead();
  return 0;
}
