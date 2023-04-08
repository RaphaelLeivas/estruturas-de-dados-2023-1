CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/c3.o
HDRS =  
CFLAGS = -g -w -c -std=c++14 -I$(INC) # DEBUGGING
# CFLAGS = -Wall -c -I$(INC) -pg # PRODUCTION

EXE = $(BIN)/c3

run:  $(EXE)
	$(EXE)

$(BIN)/c3: $(OBJS)
	$(CC) -pg -o $(BIN)/c3 $(OBJS) $(LIBS)

$(OBJ)/c3.o: $(HDRS) $(SRC)/c3.c
	$(CC) $(CFLAGS) -o $(OBJ)/c3.o $(SRC)/c3.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
