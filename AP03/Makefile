CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c9.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c9

run:  $(EXE)
	$(EXE)

$(BIN)/c9: $(OBJS)
	$(CC) -pg -o $(BIN)/c9 $(OBJS) $(LIBS)

$(OBJ)/c9.o: $(HDRS) $(SRC)/c9.c
	$(CC) $(CFLAGS) -o $(OBJ)/c9.o $(SRC)/c9.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
