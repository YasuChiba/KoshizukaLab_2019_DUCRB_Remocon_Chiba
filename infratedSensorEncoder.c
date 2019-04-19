#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define INFRATED_MODULE 0

int main(void)
{
  wiringPiSetup();
  pinMode(INFRATED_MODULE, OUTPUT);

  for (int i = 0; i < 1000; i++)
  {
    printf("ttttt\n");
    digitalWrite(INFRATED_MODULE, HIGH);
    delay(100);
    digitalWrite(INFRATED_MODULE, LOW);
    delay(100);
  }

  return 0;
}
