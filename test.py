import time
import RPi.GPIO as GPIO
import dht11


COUNT = 100
PIN = 7
GPIO.cleanup()
GPIO.setmode(GPIO.BOARD)
instance = dht11.DHT11(pin=PIN)


def printTemperature():
  result = instance.read()
  if result.is_valid():
    print("temperature: " + str(result.temperature))
  else:
    print("cannot read temperature")

def main():
  while True:
    printTemperature()
    timer.sleep(5)


def destroy():
	GPIO.cleanup()

if __name__ == '__main__':
	try:
		main()
	except KeyboardInterrupt:
		destroy() 




'''
for _ in xrange(COUNT):
    GPIO.output(PIN,True)
    time.sleep(1.0)
    GPIO.output(PIN,False)
    time.sleep(1.0)
'''