CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/NodeItem.o $(OBJ)/Cell.o $(OBJ)/LinkedList.o $(OBJ)/HuffmanTree.o $(OBJ)/Utils.o $(OBJ)/Compressor.o $(OBJ)/TP03.o
HDRS = $(INC)/NodeItem.hpp $(INC)/Cell.hpp $(INC)/LinkedList.hpp $(INC)/HuffmanTree.hpp $(INC)/Utils.hpp $(INC)/Compressor.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/TP03

UNCOMPRESSED_FILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP03/fileToComp.txt
COMPRESSED_FILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP03/fileToDecomp.txt

run:  $(EXE)
	$(EXE) -c $(UNCOMPRESSED_FILE) $(COMPRESSED_FILE)
	$(EXE) -d $(COMPRESSED_FILE) $(UNCOMPRESSED_FILE)

debug:  $(EXE)
	gdb --args $(EXE)

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE) -c $(UNCOMPRESSED_FILE) $(COMPRESSED_FILE)

$(BIN)/TP03: $(OBJS)
	$(CC) -pg -o $(BIN)/TP03 $(OBJS) $(LIBS)

$(OBJ)/TP03.o: $(HDRS) $(SRC)/TP03.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TP03.o $(SRC)/TP03.cpp

$(OBJ)/NodeItem.o: $(HDRS) $(SRC)/NodeItem.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/NodeItem.o $(SRC)/NodeItem.cpp

$(OBJ)/Cell.o: $(HDRS) $(SRC)/Cell.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Cell.o $(SRC)/Cell.cpp

$(OBJ)/LinkedList.o: $(HDRS) $(SRC)/LinkedList.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/LinkedList.o $(SRC)/LinkedList.cpp

$(OBJ)/HuffmanTree.o: $(HDRS) $(SRC)/HuffmanTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/HuffmanTree.o $(SRC)/HuffmanTree.cpp

$(OBJ)/Utils.o: $(HDRS) $(SRC)/Utils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Utils.o $(SRC)/Utils.cpp

$(OBJ)/Compressor.o: $(HDRS) $(SRC)/Compressor.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Compressor.o $(SRC)/Compressor.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
