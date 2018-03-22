CC = gcc
LIB = -lm
TEMPS = -save-temps
FILES = main.c fun.c
OUT_EXE = ejecutable

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE) $(LIB) $(TEMPS) -Wall

clean:
	rm -f *.o core

rebuild: clean build 
