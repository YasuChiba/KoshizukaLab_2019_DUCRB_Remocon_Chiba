import time
import RPi.GPIO as GPIO


COUNT = 100
PIN = 7
GPIO.setmode(GPIO.BOARD)



def readDHT11():
	GPIO.setup(PIN,GPIO.OUT)
	GPIO.output(PIN, GPIO.HIGH)
	time.sleep(0.05)
	GPIO.output(PIN, GPIO.LOW)
	time.sleep(0.02)
	GPIO.setup(PIN, GPIO.IN, GPIO.PUD_UP)

	data = []
	while True:
		current = GPIO.input(PIN)


	pass


def main():

	pass

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