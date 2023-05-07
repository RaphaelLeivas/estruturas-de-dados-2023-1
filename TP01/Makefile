CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Stack.o $(OBJ)/CircularQueue.o $(OBJ)/NumExp.o $(OBJ)/NumSolver.o $(OBJ)/TP01.o
HDRS = $(INC)/Stack.hpp $(INC)/CircularQueue.hpp $(INC)/NumExp.hpp $(INC)/NumSolver.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -std=c++14 -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/TP01

INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s1.n5.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s2.n5.p.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s3.n5.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s4.n5.p.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s5.n5.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s6.n5.p.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s7.n5.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s8.n5.p.in

# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s11.n10.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s12.n10.p.in

# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s35.n50.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s36.n50.p.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s37.n50.i.in
# INPUTFILE = /mnt/c/dev/estruturas-de-dados-2023-1/TP01/TP1entrada/entdouble.s38.n50.p.in

run:  $(EXE)
	$(EXE) -f $(INPUTFILE)

debug:  $(EXE)
	gdb --args $(EXE) -f $(INPUTFILE)

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE) -f $(INPUTFILE)

$(BIN)/TP01: $(OBJS)
	$(CC) -pg -o $(BIN)/TP01 $(OBJS) $(LIBS)

$(OBJ)/TP01.o: $(HDRS) $(SRC)/TP01.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/TP01.o $(SRC)/TP01.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp

$(OBJ)/CircularQueue.o: $(HDRS) $(SRC)/CircularQueue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/CircularQueue.o $(SRC)/CircularQueue.cpp

$(OBJ)/NumExp.o: $(HDRS) $(SRC)/NumExp.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/NumExp.o $(SRC)/NumExp.cpp

$(OBJ)/NumSolver.o: $(HDRS) $(SRC)/NumSolver.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/NumSolver.o $(SRC)/NumSolver.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
