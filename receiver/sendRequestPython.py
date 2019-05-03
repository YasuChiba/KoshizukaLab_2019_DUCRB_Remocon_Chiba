import sys
import requests
import json
import time
import RPi.GPIO as GPIO


def destroy():
	GPIO.output(13, GPIO.LOW)     # led off
	GPIO.cleanup()   


GPIO.cleanup()
GPIO.setmode(GPIO.BOARD)
GPIO.setup(13, GPIO.OUT)

GPIO.output(infraredSensorPin, GPIO.HIGH)  # led on
time.sleep(2)
GPIO.output(infraredSensorPin, GPIO.LOW) # led off


print("python called")
args = sys.argv
print("rrrrrr  ", args[1])

