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
OBJS = $(OBJ)/memlog.o $(OBJ)/AP09.o
HDRS = $(INC)/memlog.h $(INC)/msgassert.h

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_DEBUG)

EXE = $(BIN)/AP09

run:  $(EXE)
	$(EXE)

dev:  $(EXE)
	$(EXE)
	valgrind -s --leak-check=full ./$(BIN)/AP09

$(BIN)/AP09: $(OBJS)
	$(CC) -pg -o $(BIN)/AP09 $(OBJS) $(LIBS)

$(OBJ)/AP09.o: $(HDRS) $(SRC)/AP09.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/AP09.o $(SRC)/AP09.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
