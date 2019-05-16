

import serial
import sys


args = sys.argv
#args[1] : roomNumber

ser = serial.Serial('/dev/serial0', 9600)

roomNumber = int(args[1])
print(roomNumber)
ser.write(roomNumber)
ser.close()



