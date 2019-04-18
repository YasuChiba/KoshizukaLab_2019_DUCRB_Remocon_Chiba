#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 0

int main(void)
{
  wiringPiSetup();
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 1000; i++)
  {
    printf("ttttt\n");
    digitalWrite(LED_PIN, HIGH);
    sleep(1);
    digitalWrite(LED_PIN, LOW);
    sleep(1);
  }

  return 0;
}