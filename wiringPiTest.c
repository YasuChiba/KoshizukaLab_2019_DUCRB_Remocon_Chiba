#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 11

int main(void)
{
  wiringPiSetupGpio();
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 10; i++)
  {
    digitalWrite(LED_PIN, HIGH);
    sleep(3);
    digitalWrite(LED_PIN, LOW);
  }

  return 0;
}