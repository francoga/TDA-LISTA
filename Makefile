CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror 
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

CFILES = lista.c pruebas_alumno.c testing.c main.c pila.c
HFILES = lista.h testing.h pila.h
EXEC_S = pruebas


build: $(CFILES)
	$(CC) $(CFLAGS) -o $(EXEC_S) $(CFILES)

run: build
	./$(EXEC_S)

valgrind: build
	valgrind $(VFLAGS) ./$(EXEC_S)

gdb: build
	gdb $(GDBFLAGS) ./$(EXEC_S)

runtime: build
	time ./$(EXEC_S)

clean:
	rm -f *.o $(EXEC_S)
