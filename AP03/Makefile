CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c13.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c13

run:  $(EXE)
	$(EXE)

$(BIN)/c13: $(OBJS)
	$(CC) -pg -o $(BIN)/c13 $(OBJS) $(LIBS)

$(OBJ)/c13.o: $(HDRS) $(SRC)/c13.c
	$(CC) $(CFLAGS) -o $(OBJ)/c13.o $(SRC)/c13.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
