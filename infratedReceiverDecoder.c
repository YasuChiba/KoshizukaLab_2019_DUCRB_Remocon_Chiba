#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define INFRATED_RECEIVER_PIN 0

void fall()
{
  printf("edgeChange   %d\n", millis());
}

void useCallback()
{
  wiringPiISR(INFRATED_RECEIVER_PIN, INT_EDGE_BOTH, *fall);
  while (1)
  {
    //printf("%d\n", millis());
    //delay(1);
  }
}

void useDigitalRead(int minimumDuration, int arrayLength)
{
  //int arrayLength = 100;
  int resultArray[arrayLength][3];
  resultArray[0][0] = 0;
  resultArray[0][1] = 0;

  int previousValue = 0;
  int value = 0;
  int counter = 1;
  int previousTime = 0;
  int currentTime = 0;

  int tmpAvg = 0;
  int tmp = 0;

  while (1)
  {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if (previousValue != value)
    {
      currentTime = micros();
      tmp = currentTime - previousTime;
      if (tmp - tmpAvg > minimumDuration)
      { //ここまでの平均から大きく離れてるとき
        resultArray[counter][0] = value;
        resultArray[counter][1] = tmp;
        resultArray[counter][2] = currentTime;
        counter++;
        //printf("%d  %d  %d\n", value, tmp,currentTime);
      }
      else
      {
        tmpAvg = (tmpAvg + tmp) / 2;
      }

      //printf("%d     %d\n", value, currentTime - previousTime);

      if (counter >= arrayLength)
      {
        break;
      }
      previousTime = currentTime;
    }
    previousValue = value;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    printf("%d  %d %d\n", resultArray[i][0], resultArray[i][1],resultArray[i][2]);
  }
}

void digitalReadTest() {
  int value = 0;
  int prevValue = 0;
  int currentTime = 0;
  int prevTime = 0;

  while(1) {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if (value != prevValue) {
      currentTime = millis();
      printf("%d  %d  %d\n", value,currentTime - prevTime, currentTime);
      prevTime = currentTime;
      delayMicroseconds(100);
    }
    prevValue = value;
  }
}

void printDigitalRead()
{
  int value = 0;
  int arrayLength = 10000;
  int array[arrayLength];
  int counter = 0;
  while (1)
  {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    array[counter] = value;
    counter++;
    if(counter > arrayLength){
      break;
    }
    //printf("%d\n",value);
    delayMicroseconds(10);
  }
  for(int i=0; i< arrayLength; i++) {
    printf("%d\n", array[i]);
  }
}



int main(int argc, char *argv[])
{
  wiringPiSetup();
  pinMode(INFRATED_RECEIVER_PIN, INPUT);
  pullUpDnControl(INFRATED_RECEIVER_PIN, PUD_UP);

  //useCallback();
  //useDigitalRead(atoi(argv[1]), atoi(argv[2]));
  //printDigitalRead();
  digitalReadTest();
  return 0;
}
