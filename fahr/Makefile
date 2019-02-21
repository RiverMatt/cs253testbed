# Makefile for new program 

CC = gcc
CFLAGS = -Wall -std=c99
EXE = fahr
OBJS = fahr.o 

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXE)
