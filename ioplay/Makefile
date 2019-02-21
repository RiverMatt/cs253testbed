# Makefile for new program 

EXE = ioplay
OBJS = ioplay.o

CC = gcc
CFLAGS = -Wall -std=c99

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXE)
