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
OBJS = $(OBJ)/MyAlgorithms.o $(OBJ)/Point.o $(OBJ)/Line.o $(OBJ)/CircularQueue.o $(OBJ)/Stack.o $(OBJ)/fecho.o
HDRS = $(INC)/MyAlgorithms.hpp $(INC)/Point.hpp $(INC)/Line.hpp $(INC)/CircularQueue.hpp $(INC)/Stack.hpp $(INC)/msgassert.h

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/fecho

run:  $(EXE)
	$(EXE)

dev:  $(EXE)
	$(EXE)
	valgrind -s --leak-check=full ./$(BIN)/fecho

$(BIN)/fecho: $(OBJS)
	$(CC) -pg -o $(BIN)/fecho $(OBJS) $(LIBS)

$(OBJ)/fecho.o: $(HDRS) $(SRC)/fecho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fecho.o $(SRC)/fecho.cpp

$(OBJ)/CircularQueue.o: $(HDRS) $(SRC)/CircularQueue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/CircularQueue.o $(SRC)/CircularQueue.cpp

$(OBJ)/MyAlgorithms.o: $(HDRS) $(SRC)/MyAlgorithms.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/MyAlgorithms.o $(SRC)/MyAlgorithms.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp

$(OBJ)/Point.o: $(HDRS) $(SRC)/Point.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Point.o $(SRC)/Point.cpp

$(OBJ)/Line.o: $(HDRS) $(SRC)/Line.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Line.o $(SRC)/Line.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
