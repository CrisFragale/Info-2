CC = gcc
LIB = -lm
TEMPS = -save-temps
FILES = *.c
OUT_EXE = ejecutable

build: $(FILES)
	$(CC) $(FILES) -o $(OUT_EXE) $(LIB) $(TEMPS) -Wall

clean:
	rm -f *.o core
	rm -f *.s core
	rm -f *.i core
	rm -f $(OUT_EXE)

rebuild: clean build