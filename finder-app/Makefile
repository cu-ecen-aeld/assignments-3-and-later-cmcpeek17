CROSS_COMPILE?=

ifeq ($(CROSS_COMPILE),aarch64-none-linux-gnu-)
	CC=$(CROSS_COMPILE)gcc
else
	CC=cc
endif

writer: writer.o

writer.o: writer.c
	$(CC) -c -g -Wall writer.c -o writer.o

clean:
	rm -f *.o writer

