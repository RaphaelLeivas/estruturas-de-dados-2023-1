CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/NodeItem.o $(OBJ)/Node.o $(OBJ)/Cell.o $(OBJ)/BinaryTree.o $(OBJ)/LinkedList.o $(OBJ)/HuffmanTree.o $(OBJ)/Utils.o $(OBJ)/TP03.o
HDRS = $(INC)/NodeItem.hpp $(INC)/Node.hpp $(INC)/Cell.hpp  $(INC)/BinaryTree.hpp $(INC)/LinkedList.hpp $(INC)/HuffmanTree.hpp $(INC)/Utils.hpp 

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/TP03

FILE_TO_COMP = /mnt/c/dev/estruturas-de-dados-2023-1/TP03/fileToComp.txt
FILE_TO_DECOMP = /mnt/c/dev/estruturas-de-dados-2023-1/TP03/fileToDecomp.txt

run:  $(EXE)
	$(EXE) -c $(FILE_TO_COMP) $(FILE_TO_DECOMP)
	$(EXE) -d $(FILE_TO_COMP) $(FILE_TO_DECOMP)

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

$(OBJ)/Cell.o: $(HDRS) $(SRC)/Cell.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Cell.o $(SRC)/Cell.cpp

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp

$(OBJ)/LinkedList.o: $(HDRS) $(SRC)/LinkedList.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/LinkedList.o $(SRC)/LinkedList.cpp

$(OBJ)/HuffmanTree.o: $(HDRS) $(SRC)/HuffmanTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/HuffmanTree.o $(SRC)/HuffmanTree.cpp

$(OBJ)/Utils.o: $(HDRS) $(SRC)/Utils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Utils.o $(SRC)/Utils.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
