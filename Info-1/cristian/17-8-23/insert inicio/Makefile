CC = gcc
LIB = -lm
TEMPS = -save-temps
FILES = insertarini.c main.c
OUT_EXE = ejecutable

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE) $(LIB) $(TEMPS) -Wall

clean:
	rm -f *.o core

rebuild: clean build 
