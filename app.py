import time
import RPi.GPIO as GPIO
import dht11

GPIO.cleanup()

def printTemperature():
  result = instance.read()
  if result.is_valid():
    print("temperature: " + str(result.temperature))
  else:
    print("cannot read temperature")



while True:
	printTemperature()
	time.sleep(10)