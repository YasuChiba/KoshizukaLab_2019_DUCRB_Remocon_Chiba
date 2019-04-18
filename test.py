import time
import RPi.GPIO as GPIO
import dht11

infraredSensorPin = 11
infraredReceivingPin = 37



def setup():
	GPIO.setmode(GPIO.BOARD)  # Numbers GPIOs by physical location
	GPIO.setup(infraredSensorPin, GPIO.OUT)   # Set infraredSensorPin's mode is output
	GPIO.output(infraredSensorPin, GPIO.HIGH)  # Set infraredSensorPin high(+3.3V) to off led
  GPIO.setup(infraredReceivingPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

  GPIO.add_event_detect(infraredReceivingPin, GPIO.FALLING, callback=receiveFalling)
  GPIO.add_event_detect(infraredReceivingPin, GPIO.RISING, callback=receiveRising)

def receiveRising():
  print("RISEEE")
  pass

def receiveFalling():
  print("FALLLL")
  pass

def loop():
	while True:
		print('...led on')
		GPIO.output(infraredSensorPin, GPIO.HIGH)  # led on
		time.sleep(0.5)
		print('led off...')
		GPIO.output(infraredSensorPin, GPIO.LOW) # led off
		time.sleep(0.5)

def destroy():
	GPIO.output(infraredSensorPin, GPIO.LOW)     # led off
	GPIO.cleanup()                     # Release resource

if __name__ == '__main__':     # Program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()