#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 7

int main(void)
{
  wiringPiSetupGpio();
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 10; i++)
  {
    printf("ttttt\n");
    digitalWrite(LED_PIN, HIGH);
    sleep(3);
    digitalWrite(LED_PIN, LOW);
    sleep(3);
  }

  return 0;
}