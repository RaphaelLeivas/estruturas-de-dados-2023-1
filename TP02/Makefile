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
OBJS = $(OBJ)/customTime.o $(OBJ)/MyAlgorithms.o $(OBJ)/Point.o $(OBJ)/Line.o $(OBJ)/List.o $(OBJ)/LinkedList.o $(OBJ)/ConvexHull.o $(OBJ)/Stack.o $(OBJ)/fecho.o
HDRS = $(INC)/customTime.h $(INC)/MyAlgorithms.hpp $(INC)/Point.hpp $(INC)/Line.hpp $(INC)/List.hpp $(INC)/LinkedList.hpp $(INC)/ConvexHull.hpp $(INC)/Stack.hpp

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_PROD)

EXE = $(BIN)/fecho

run:  $(EXE)
	$(EXE)

debug:  $(EXE)
	gdb --args $(EXE) $(INPUTFILE)

$(BIN)/fecho: $(OBJS)
	$(CC) -pg -o $(BIN)/fecho $(OBJS) $(LIBS)

$(OBJ)/fecho.o: $(HDRS) $(SRC)/fecho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fecho.o $(SRC)/fecho.cpp

$(OBJ)/MyAlgorithms.o: $(HDRS) $(SRC)/MyAlgorithms.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/MyAlgorithms.o $(SRC)/MyAlgorithms.cpp

$(OBJ)/customTime.o: $(HDRS) $(SRC)/customTime.c
	$(CC) $(CFLAGS) -o $(OBJ)/customTime.o $(SRC)/customTime.c

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp

$(OBJ)/Point.o: $(HDRS) $(SRC)/Point.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Point.o $(SRC)/Point.cpp

$(OBJ)/Line.o: $(HDRS) $(SRC)/Line.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Line.o $(SRC)/Line.cpp

$(OBJ)/List.o: $(HDRS) $(SRC)/List.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/List.o $(SRC)/List.cpp

$(OBJ)/LinkedList.o: $(HDRS) $(SRC)/LinkedList.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/LinkedList.o $(SRC)/LinkedList.cpp

$(OBJ)/ConvexHull.o: $(HDRS) $(SRC)/ConvexHull.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/ConvexHull.o $(SRC)/ConvexHull.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
