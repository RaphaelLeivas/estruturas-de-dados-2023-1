#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa matop
# Autor		: Raphael Henrique Braga Leivas (raphaelbleivas@ufmg.br)
# Histórico	: 2023-03-22 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make run - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/ap02.o $(OBJ)/customTime.o $(OBJ)/fibonacci.o $(OBJ)/factorial.o
HDRS = $(INC)/msgassert.h $(INC)/customTime.h $(INC)/fibonacci.h $(INC)/factorial.h
CFLAGS = -Wall -c -I$(INC) -pg

EXE = $(BIN)/ap02

run:  $(EXE)
	$(EXE) -b
	gprof $(EXE) -a gmon.out > tmp/analise.txt	

$(BIN)/ap02: $(OBJS)
	$(CC) -pg -o $(BIN)/ap02 $(OBJS) $(LIBS)

$(OBJ)/ap02.o: $(HDRS) $(SRC)/ap02.c
	$(CC) $(CFLAGS) -o $(OBJ)/ap02.o $(SRC)/ap02.c 

$(OBJ)/customTime.o: $(HDRS) $(SRC)/customTime.c
	$(CC) $(CFLAGS) -o $(OBJ)/customTime.o $(SRC)/customTime.c 

$(OBJ)/factorial.o: $(HDRS) $(SRC)/factorial.c
	$(CC) $(CFLAGS) -o $(OBJ)/factorial.o $(SRC)/factorial.c 

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.c
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
