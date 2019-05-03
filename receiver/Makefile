
CC := gcc

receiver: infratedReceiver.o decoder.o
	$(CC) -o receiver infratedReceiver.o decoder.o -I/usr/local/include -L/usr/local/lib -lwiringPi

infratedReceiver.o: infratedReceiver.c infratedReceiver.h
	$(CC) -c $*.c

decoder.o: decoder.c decoder.h
	$(CC) -c $*.c

clean:
	$(RM) *.o
	$(RM) receiver