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
OBJS = $(OBJ)/CircularQueue.o $(OBJ)/AP04.o
HDRS = $(INC)/CircularQueue.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/AP04

run:  $(EXE)
	$(EXE)

$(BIN)/AP04: $(OBJS)
	$(CC) -pg -o $(BIN)/AP04 $(OBJS) $(LIBS)

$(OBJ)/AP04.o: $(HDRS) $(SRC)/AP04.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/AP04.o $(SRC)/AP04.cpp

$(OBJ)/CircularQueue.o: $(HDRS) $(SRC)/CircularQueue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/CircularQueue.o $(SRC)/CircularQueue.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
