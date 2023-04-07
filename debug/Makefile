CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/primes.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/primes

run:  $(EXE)
	$(EXE) -b
	gprof $(EXE) -a gmon.out > tmp/analise.txt	

$(BIN)/primes: $(OBJS)
	$(CC) -pg -o $(BIN)/primes $(OBJS) $(LIBS)

$(OBJ)/primes.o: $(HDRS) $(SRC)/primes.c
	$(CC) $(CFLAGS) -o $(OBJ)/primes.o $(SRC)/primes.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
