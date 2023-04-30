CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Stack.o $(OBJ)/main.o
HDRS = $(INC)/Stack.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/main

run:  $(EXE)
	$(EXE) -f args

debug:  $(EXE)
	gdb --args $(EXE) -f args

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE) -f args

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
