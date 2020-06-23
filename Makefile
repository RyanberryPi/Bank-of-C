CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic

bank: bank.o
	$(CC) bank.o -o $@

bank.o: bank.c
	$(CC) $(CFLAGS) -c bank.c -o $@

clean:
	rm *.o
	rm bank
