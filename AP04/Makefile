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
OBJS = $(OBJ)/CircularQueue.o $(OBJ)/memlog.o $(OBJ)/Stack.o $(OBJ)/AP04.o
HDRS = $(INC)/CircularQueue.hpp $(INC)/memlog.h $(INC)/Stack.hpp $(INC)/msgassert.h

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_DEBUG)

EXE = $(BIN)/AP04

run:  $(EXE)
	$(EXE)

dev:  $(EXE)
	$(EXE)
	valgrind -s --leak-check=full ./$(BIN)/AP04

$(BIN)/AP04: $(OBJS)
	$(CC) -pg -o $(BIN)/AP04 $(OBJS) $(LIBS)

$(OBJ)/AP04.o: $(HDRS) $(SRC)/AP04.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/AP04.o $(SRC)/AP04.cpp

$(OBJ)/CircularQueue.o: $(HDRS) $(SRC)/CircularQueue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/CircularQueue.o $(SRC)/CircularQueue.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
