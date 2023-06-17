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
OBJS = $(OBJ)/memlog.o $(OBJ)/AP10.o
HDRS = $(INC)/memlog.h $(INC)/msgassert.h

CFLAGS_DEBUG = -g -w -c -std=c++14 -I$(INC) 
CFLAGS_PROD = -Wall -c -I$(INC) -pg
CFLAGS = $(CFLAGS_DEBUG)

EXE = $(BIN)/AP10

all: $(EXE) # cria o binario, chamando a regra $(OBJ)/AP10.o: 
	@echo "Binary created. Now calling the binary"
	$(EXE) 

$(BIN)/AP10: $(OBJS)
	@echo "Creating AP10 binary"
	$(CC) -pg -o $(BIN)/AP10 $(OBJS) $(LIBS)

$(OBJ)/AP10.o: $(HDRS) $(SRC)/AP10.c
	@echo "Compiling AP10"
	$(CC) $(CFLAGS) -Dm=2 -DCARGA=100 -o $(OBJ)/AP10.o $(SRC)/AP10.c

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	@echo "Compiling memlog"
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c
	
clean:
	@echo "Removing everything"
	rm -f $(EXE) $(OBJS) gmon.out
