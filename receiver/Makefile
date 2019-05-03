
CC := gcc

receiver: infratedReceiver.o decoder.o sendRequest.o
	$(CC) -o receiver infratedReceiver.o decoder.o sendRequest.o -I/usr/local/include -L/usr/local/lib -lwiringPi

infratedReceiver.o:
	$(CC) -c $*.c

decoder.o:
	$(CC) -c $*.c

sendRequest.o: 
	$(CC) -c $*.c

clean:
	$(RM) *.o
	$(RM) receiver