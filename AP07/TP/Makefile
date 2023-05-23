CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/customTime.o $(OBJ)/AP07.o
HDRS = $(INC)/customTime.h

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/AP07

run:  $(EXE)
	$(EXE) -f args

debug:  $(EXE)
	gdb --args $(EXE) -f args

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE) -f args

$(BIN)/AP07: $(OBJS)
	$(CC) -pg -o $(BIN)/AP07 $(OBJS) $(LIBS)

$(OBJ)/AP07.o: $(HDRS) $(SRC)/AP07.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/AP07.o $(SRC)/AP07.cpp

$(OBJ)/customTime.o: $(HDRS) $(SRC)/customTime.c
	$(CC) $(CFLAGS) -o $(OBJ)/customTime.o $(SRC)/customTime.c 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
