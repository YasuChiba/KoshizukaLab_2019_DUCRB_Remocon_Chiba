import time
import RPi.GPIO as GPIO
import dht11


def setup():
	GPIO.cleanup()
	'''
	COUNT = 100
	DHT11_PIN = 7
	GPIO.cleanup()
	GPIO.setmode(GPIO.BOARD)
	dht11Instance = dht11.DHT11(pin=DHT11_PIN)
	'''

def printTemperature():
  result = dht11Instance.read()
  if result.is_valid():
    print("temperature: " + str(result.temperature))
  else:
    print("cannot read temperature")


setup()
while True:
	#printTemperature()
	time.sleep(50)