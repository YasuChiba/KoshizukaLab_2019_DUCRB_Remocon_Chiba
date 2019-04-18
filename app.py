import time

import RPi.GPIO as GPIO
import dht11
import datetime

# initialize GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.cleanup()
# read data using pin 14
instance = dht11.DHT11(pin=7)



def getTemprature():
		result = instance.read()
		return result.temperature

while True:
		print(getTemprature())
		time.sleep(5)
