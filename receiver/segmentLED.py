

import serial


args = sys.argv
print(args)
#args[1] : roomNumber

ser = serial.Serial('/dev/serial0', 9600)

roomNumber = int(args[1])
ser.write(roomNumber)
ser.close()



