CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c19.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c19

run:  $(EXE)
	$(EXE)

$(BIN)/c19: $(OBJS)
	$(CC) -pg -o $(BIN)/c19 $(OBJS) $(LIBS)

$(OBJ)/c19.o: $(HDRS) $(SRC)/c19.c
	$(CC) $(CFLAGS) -o $(OBJ)/c19.o $(SRC)/c19.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
