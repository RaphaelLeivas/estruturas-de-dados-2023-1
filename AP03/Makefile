CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c5.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c5

run:  $(EXE)
	$(EXE)

$(BIN)/c5: $(OBJS)
	$(CC) -pg -o $(BIN)/c5 $(OBJS) $(LIBS)

$(OBJ)/c5.o: $(HDRS) $(SRC)/c5.c
	$(CC) $(CFLAGS) -o $(OBJ)/c5.o $(SRC)/c5.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
