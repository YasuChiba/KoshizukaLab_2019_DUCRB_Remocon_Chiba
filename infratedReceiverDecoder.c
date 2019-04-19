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
  int arrayLength = 100;
  int resultArray[arrayLength][2];

  int previousValue = 0;
  int value = 0;
  int counter = 0;
  while (1)
  {
    value = digitalRead(INFRATED_RECEIVER_PIN);
    if (previousValue != value)
    {
      //resultArray[counter][0] = value;
      //resultArray[counter][1] = millis();
      printf("%d     %d\n", value, millis());
      //counter++;

      if (counter >= arrayLength)
      {
        break;
      }
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
