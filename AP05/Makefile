CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Stack.o $(OBJ)/AP05.o
HDRS = $(INC)/Stack.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/AP05

run:  $(EXE)
	$(EXE) -f args

debug:  $(EXE)
	gdb --args $(EXE) -f args

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE) -f args

$(BIN)/AP05: $(OBJS)
	$(CC) -pg -o $(BIN)/AP05 $(OBJS) $(LIBS)

$(OBJ)/AP05.o: $(HDRS) $(SRC)/AP05.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/AP05.o $(SRC)/AP05.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
