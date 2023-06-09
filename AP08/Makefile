#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa analisamem
# Autor		: Wagner Meira Jr. (meira@dcc.ufmg.br)
# Histórico	: 2021-10-30 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#		: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = gcc
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pilhaindexada.o $(OBJ)/analisamem.o
TOBJS = $(OBJ)/pilhaindexada.o $(OBJ)/AP08.o
HDRS = $(INC)/pilhaindexada.h $(INC)/msgassert.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/analisamem

TEST = $(BIN)/AP08

all: test use

use: $(EXE)
	if test -d /tmp/out; then rm -rf /tmp/out; fi
	mkdir /tmp/out
	$(EXE) -i teste/multlog.out -p /tmp/out/mult
	$(EXE) -i teste/somalog.out -p /tmp/out/soma
	$(EXE) -i teste/transplog.out -p /tmp/out/transp
	n /tmp/out/*.gp
	ls /tmp/out/

run: $(TEST)
	$(BIN)/AP08

bin: $(EXE) $(TEST)

$(BIN)/AP08: $(TOBJS)
	$(CC) -g -o $(BIN)/AP08 $(TOBJS) $(LIBS)

$(BIN)/analisamem: $(OBJS)
	$(CC) -g -o $(BIN)/analisamem $(OBJS) $(LIBS)

$(OBJ)/analisamem.o: $(HDRS) $(SRC)/analisamem.c
	$(CC) $(CFLAGS) -o $(OBJ)/analisamem.o $(SRC)/analisamem.c 

$(OBJ)/AP08.o: $(HDRS) $(SRC)/AP08.c
	$(CC) $(CFLAGS) -o $(OBJ)/AP08.o $(SRC)/AP08.c 

$(OBJ)/pilhaindexada.o: $(HDRS) $(SRC)/pilhaindexada.c
	$(CC) $(CFLAGS) -o $(OBJ)/pilhaindexada.o $(SRC)/pilhaindexada.c 

clean:
	rm -f $(EXE) $(TEST) $(OBJS)  $(TOBJS)
