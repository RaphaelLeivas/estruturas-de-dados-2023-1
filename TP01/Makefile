CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Stack.o $(OBJ)/NumExp.o $(OBJ)/NumSolver.o $(OBJ)/TP01.o
HDRS = $(INC)/Stack.hpp $(INC)/NumExp.hpp $(INC)/NumSolver.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/TP01

run:  $(EXE)
	$(EXE)

debug:  $(EXE)
	gdb /mnt/c/dev/estruturas-de-dados-2023-1/TP01/bin/TP01

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable ./$(BIN)/TP01

$(BIN)/TP01: $(OBJS)
	$(CC) -pg -o $(BIN)/TP01 $(OBJS) $(LIBS)

$(OBJ)/TP01.o: $(HDRS) $(SRC)/TP01.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TP01.o $(SRC)/TP01.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp

$(OBJ)/NumExp.o: $(HDRS) $(SRC)/NumExp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/NumExp.o $(SRC)/NumExp.cpp

$(OBJ)/NumSolver.o: $(HDRS) $(SRC)/NumSolver.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/NumSolver.o $(SRC)/NumSolver.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
