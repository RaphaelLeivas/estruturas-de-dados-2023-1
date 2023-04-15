#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Raphael Henrique Braga Leivas (raphaelbleivas@ufmg.br)
# Histórico	: 2023-03-22 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make run - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/Stack.o $(OBJ)/NumExp.o $(OBJ)/TP01.o
HDRS = $(INC)/Stack.hpp $(INC)/NumExp.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/TP01

run:  $(EXE)
	$(EXE)

dev:  $(EXE)
	$(EXE)
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
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
