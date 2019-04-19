#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define INFRATED_RECEIVER_PIN 0

int main(void)
{
  wiringPiSetup();
  pinMode(INFRATED_RECEIVER_PIN, INPUT);

  int result = 0;

  while (1)
  {
    result = digitalRead(INFRATED_RECEIVER_PIN);
    printf("%d\n", result);
    delay(100);
  }

  return 0;
}
