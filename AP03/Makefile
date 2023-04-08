CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c11.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c11

run:  $(EXE)
	$(EXE)

$(BIN)/c11: $(OBJS)
	$(CC) -pg -o $(BIN)/c11 $(OBJS) $(LIBS)

$(OBJ)/c11.o: $(HDRS) $(SRC)/c11.c
	$(CC) $(CFLAGS) -o $(OBJ)/c11.o $(SRC)/c11.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
