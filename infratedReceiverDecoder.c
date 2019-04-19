#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

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

void useDigitalRead()
{
  int arrayLength = 50;
  int resultArray[arrayLength][2];
  resultArray[0][0] = 0;
  resultArray[0][1] = 0;

  int previousValue = 0;
  int value = 0;
  int counter = 1;
  int previousMills = 0;
  int currentMills = 0;

  int tmpAvg = 0;
  int tmp = 0;

  while (1)
  {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if (previousValue != value)
    {
      currentMills = millis();
      tmp = currentMills - previousMills;
      if (tmp - tmpAvg > 60)
      { //ここまでの平均から大きく離れてるとき
        resultArray[counter][0] = value;
        resultArray[counter][1] = tmp;
        counter++;
      }
      else
      {
        tmpAvg = (tmpAvg + tmp) / 2;
      }

      //printf("%d     %d\n", value, currentMills - previousMills);

      if (counter >= arrayLength)
      {
        break;
      }
      previousMills = currentMills;
    }
    previousValue = value;
  }

  for (int i = 0; i < arrayLength; i++)
  {
    printf("%d  %d \n", resultArray[i][0], resultArray[i][1]);
  }
}

int main(void)
{
  wiringPiSetup();
  pinMode(INFRATED_RECEIVER_PIN, INPUT);
  pullUpDnControl(INFRATED_RECEIVER_PIN, PUD_UP);

  //useCallback();
  useDigitalRead();
  return 0;
}
