# Makefile for new program 

EXE = fahr
OBJS = fahr.o 

CC = gcc
CFLAGS = -Wall -std=c99

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXE)
