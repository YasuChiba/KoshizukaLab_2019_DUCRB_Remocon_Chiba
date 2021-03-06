#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>                                                             

#include "decoder.h"
#include "infratedReceiver.h"

#define HEADER_H_
#include "header.h"

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

//2: end signal, 3: error
int _decode(int pulseLength1, int pulseLength2, int pulseValue1, int pulseValue2) {
  //printf("%d  %d\n",pulseLength1,pulseLength2);

  int _isCloseEnough1_100 = isCloseEnough(100,pulseLength1);
  int _isCloseEnough2_100 = isCloseEnough(50,pulseLength2);
  
  if(isCloseEnough(20,pulseLength1) == 1 && isCloseEnough(10,pulseLength2) == 1) {
    return 0;
  } else if(isCloseEnough(20,pulseLength1) == 1 && isCloseEnough(20,pulseLength2) == 1) {
    return 1;
  } else if(isCloseEnough(100,pulseLength1) == 1 && isCloseEnough(50,pulseLength2) == 1) {
    return 2;
  }
  return 3;
}

void receive() {

  int value = 0;
  int prevValue = 0;

  int startTime = 0;
  int now = 0;
  int pulseLength1 = 0;
  int pulseValue1 = 0;
  int pulseLength2 = 0;
  int pulseValue2 = 0;

  int decodeResult = 0;

  int commands[CODE_LENGTH];
  int commandsIndex = 0;

  while(1) {
    waitUntilStartSignal();
    startTime = millis();
    prevValue = 0;
    commandsIndex = 0;
    printf("\nStart  \n");

    while(1) {
      value = digitalRead(INFRATED_RECEIVER_PIN);
      if(value != prevValue) {
        now = millis();
        pulseLength1 = now - startTime;
        startTime = now;
        prevValue = value;
        pulseValue1 = value;
        while(1) {
          value = digitalRead(INFRATED_RECEIVER_PIN);
          if(value != prevValue) {
            now = millis();
            pulseLength2 = now - startTime;
            startTime = now;
            pulseValue2 = value;
            break;
          }
        }
        decodeResult = _decode(pulseLength1,pulseLength2, pulseValue1, pulseValue2);
        if(decodeResult == 2) {
          printf("end \n");
          break;
        }
        commands[commandsIndex] = decodeResult;
        commandsIndex += 1;
        if(commandsIndex > CODE_LENGTH) {
          printf("error  %d\n", commandsIndex);
          break;
        }
        printf("%d  \n", decodeResult);
      }
      prevValue = value;
    }
    decode(commands);
    
  }
}

void receiveTest() {
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
  } else if(strcmp(argv[1], "receiveTest") == 0) {
    receiveTest();
  } else if(strcmp(argv[1], "receive") == 0) {
    receive();
  }
  return 0;
}
