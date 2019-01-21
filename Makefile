CC=gcc
CFLAGS=-I.
DEPS = sudokuhelper.h
OBJ = main.o sudokuhelper.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sudoku: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)