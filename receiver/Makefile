
CC := gcc

receiver: infratedReceiver.o decoder.o
	$(CC) -o receiver infratedReceiver.o decoder.o sendRequest.o -I/usr/local/include -L/usr/local/lib -lwiringPi

infratedReceiver.o: infratedReceiver.c infratedReceiver.h
	$(CC) -c $*.c

decoder.o: decoder.c decoder.h sendRequest.h
	$(CC) -c $*.c

sendRequest.o: 
	$(CC) -c $*.c

clean:
	$(RM) *.o
	$(RM) receiver