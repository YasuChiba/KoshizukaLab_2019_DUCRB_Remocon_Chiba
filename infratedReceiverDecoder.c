#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define INFRATED_RECEIVER_PIN 0

void fall()
{
  print("fall \n");
}

int main(void)
{
  wiringPiSetup();
  pinMode(INFRATED_RECEIVER_PIN, INPUT);
  pullUpDnControl(INFRATED_RECEIVER_PIN, PUD_UP);
  wiringPiISR(INFRATED_RECEIVER_PIN, INT_EDGE_FALLING, *fall);
  int result = 0;
  while (1)
  {
    //result = digitalRead(INFRATED_RECEIVER_PIN);
    printf("%d       %d\n", result, millis());
    delay(100);
  }

  return 0;
}
