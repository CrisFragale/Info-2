CC = gcc
LIB = -lm
TEMPS = -save-temps
FILES = *.c
OUT_EXE = ejec

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE) $(LIB) $(TEMPS) -Wall

clean:
	rm -f *.o core

rebuild: clean build 
