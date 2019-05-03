import sys
import requests
import json
import time
import RPi.GPIO as GPIO

ledPin = 13
def destroy():
	GPIO.output(ledPin, GPIO.LOW)     # led off

GPIO.setmode(GPIO.BOARD)
GPIO.setup(ledPin, GPIO.OUT)

GPIO.output(ledPin, GPIO.HIGH)  # led on
time.sleep(2)
GPIO.output(ledPin, GPIO.LOW) # led off


print("python called")
args = sys.argv
print("rrrrrr  ", args[1])

