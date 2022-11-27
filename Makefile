FLAGS= -Wall
CC= gcc
all:main
main: main.o my_mat.o
	$(CC) $(FLAGS) -o prog main.o my_mat.o

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

.PHONY:clean all
clean:
	rm -f *.o prog
