CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c7.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c7

run:  $(EXE)
	$(EXE)

$(BIN)/c7: $(OBJS)
	$(CC) -pg -o $(BIN)/c7 $(OBJS) $(LIBS)

$(OBJ)/c7.o: $(HDRS) $(SRC)/c7.c
	$(CC) $(CFLAGS) -o $(OBJ)/c7.o $(SRC)/c7.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
