CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/NodeItem.o $(OBJ)/Node.o $(OBJ)/BinaryTree.o $(OBJ)/TP03.o
HDRS = $(INC)/NodeItem.hpp $(INC)/Node.hpp $(INC)/BinaryTree.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/TP03

INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP03/TP1entrada/entdouble.s1.n5.i.in

run:  $(EXE)
	$(EXE)

debug:  $(EXE)
	gdb --args $(EXE)

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE)

$(BIN)/TP03: $(OBJS)
	$(CC) -pg -o $(BIN)/TP03 $(OBJS) $(LIBS)

$(OBJ)/TP03.o: $(HDRS) $(SRC)/TP03.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TP03.o $(SRC)/TP03.cpp

$(OBJ)/NodeItem.o: $(HDRS) $(SRC)/NodeItem.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/NodeItem.o $(SRC)/NodeItem.cpp

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
