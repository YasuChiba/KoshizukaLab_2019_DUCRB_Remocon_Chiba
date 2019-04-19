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
    delay(1);
  }
}

void useDigitalRead()
{
  int result = 0;
  int reasultAnalog = 0;
  while (1)
  {
    result = digitalRead(INFRATED_RECEIVER_PIN);
    reasultAnalog = analogRead(INFRATED_RECEIVER_PIN);
    printf("%d:%d     %d\n", result, reasultAnalog, millis());
    delay(1);
  }
}

int main(void)
{
  wiringPiSetup();
  pinMode(INFRATED_RECEIVER_PIN, INPUT);
  pullUpDnControl(INFRATED_RECEIVER_PIN, PUD_UP);

  useCallback();

  return 0;
}
