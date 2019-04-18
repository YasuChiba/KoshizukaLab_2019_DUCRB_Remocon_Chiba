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
    delay(10);
    digitalWrite(LED_PIN, LOW);
    delay(10)
  }

  return 0;
}