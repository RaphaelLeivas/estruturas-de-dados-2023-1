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
OBJS = $(OBJ)/LinkedList.o $(OBJ)/studies.o
HDRS = $(INC)/LinkedList.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_DEBUG)

EXE = $(BIN)/studies

run:  $(EXE)
	$(EXE)

dev:  $(EXE)
	$(EXE)
	valgrind -s --leak-check=full ./$(BIN)/studies

$(BIN)/studies: $(OBJS)
	$(CC) -pg -o $(BIN)/studies $(OBJS) $(LIBS)

$(OBJ)/studies.o: $(HDRS) $(SRC)/studies.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/studies.o $(SRC)/studies.cpp

$(OBJ)/LinkedList.o: $(HDRS) $(SRC)/LinkedList.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/LinkedList.o $(SRC)/LinkedList.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
