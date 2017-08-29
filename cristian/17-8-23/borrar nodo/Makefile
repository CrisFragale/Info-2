CC = gcc
LIB = -lm
TEMPS = -save-temps
FILES = main.c lista.c
OUT_EXE = ejec

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE) $(LIB) $(TEMPS) -Wall

clean:
	rm -f *.o core

rebuild: clean build 
