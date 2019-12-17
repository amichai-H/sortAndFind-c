CC=gcc
AR=ar
FLAGS= -Wall -g

all: isort txtfind
isort: main.o sortlib.o
	$(CC) $(FLAGS) -o isort main.o sortlib.o
txtfind: maint.o txtfindlib.o
	$(CC) $(FLAGS) -o txtfind maint.o txtfindlib.c
main.o: main.c sortlib.h
	$(CC) $(FLAGS) -c main.c
sortlib.o: sortlib.c sortlib.h
	$(CC) $(FLAGS) -c sortlib.c
maint.o: maint.c txtfindlib.h
	$(CC) $(FLAGS) -c maint.c
txtfindlib.o: txtfindlib.c txtfindlib.h
	$(CC) $(FLAGS) -c txtfindlib.c
clean:
	rm isort txtfind *.o

.PHONY: clean all mymathd mymaths