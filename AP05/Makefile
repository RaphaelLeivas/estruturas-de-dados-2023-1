CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Item.o $(OBJ)/Node.o $(OBJ)/BinaryTree.o $(OBJ)/AP05.o
HDRS = $(INC)/Item.hpp $(INC)/Node.hpp $(INC)/BinaryTree.hpp

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

$(OBJ)/Item.o: $(HDRS) $(SRC)/Item.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Item.o $(SRC)/Item.cpp

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out
