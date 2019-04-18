#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 0
#define WAIT_TIME 100000 //100000マイクロ秒　＝＝　0.1秒

int main(void)
{
  wiringPiSetup();
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < 1000; i++)
  {
    printf("ttttt\n");
    digitalWrite(LED_PIN, HIGH);
    usleep(WAIT_TIME);
    digitalWrite(LED_PIN, LOW);
    usleep(WAIT_TIME);
  }

  return 0;
}