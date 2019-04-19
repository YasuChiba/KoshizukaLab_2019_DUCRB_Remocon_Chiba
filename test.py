import time
import RPi.GPIO as GPIO
import dht11

infraredSensorPin = 37
infraredReceivingPin = 11



def setup():
  GPIO.cleanup()
  GPIO.setmode(GPIO.BOARD)
  #GPIO.setup(infraredSensorPin, GPIO.OUT)
  #GPIO.output(infraredSensorPin, GPIO.HIGH)
  GPIO.setup(infraredReceivingPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)
  
  GPIO.add_event_detect(infraredReceivingPin, GPIO.FALLING, callback=receiveFalling)

def receiveFalling(gpio_pin):
  print("FALLLL  " + str(gpio_pin))
  time.sleep(1)
  print("next")


def loop():
  while True:
    time.sleep(0.5)
  pass
  '''
	while True:
		#print('...led on')
		GPIO.output(infraredSensorPin, GPIO.HIGH)  # led on
		time.sleep(0.5)
		#print('led off...')
		GPIO.output(infraredSensorPin, GPIO.LOW) # led off
		time.sleep(0.5)
  '''
def destroy():
	GPIO.output(infraredSensorPin, GPIO.LOW)     # led off
	GPIO.cleanup()                     # Release resource

if __name__ == '__main__':     # Program start from here
	setup()
	try:
		loop()
	except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
		destroy()