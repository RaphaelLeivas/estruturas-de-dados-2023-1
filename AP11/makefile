CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Relacao.o $(OBJ)/ConjuntoDisjunto.o $(OBJ)/main.o
HDRS = $(INC)/Relacao.hpp $(INC)/ConjuntoDisjunto.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/main

run: $(EXE) # cria o binario, chamando a regra $(OBJ)/main.o: 
	@echo "Binary created. Now calling the binary"
	$(EXE)
	gnuplot plot.plt

valgrind:
	valgrind -s --leak-check=full --show-leak-kinds=reachable $(EXE)

$(BIN)/main: $(OBJS)
	@echo "Creating main binary"
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	@echo "Compiling main"
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Relacao.o: $(HDRS) $(SRC)/Relacao.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Relacao.o $(SRC)/Relacao.cpp

$(OBJ)/ConjuntoDisjunto.o: $(HDRS) $(SRC)/ConjuntoDisjunto.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ConjuntoDisjunto.o $(SRC)/ConjuntoDisjunto.cpp
	
clean:
	@echo "Removing everything"
	rm -f $(EXE) $(OBJS) gmon.out

