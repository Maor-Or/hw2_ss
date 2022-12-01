FLAGS= -Wall
CC= gcc
all:connections

connections: main.o libmy_mat.so
	$(CC) $(FLAGS) -o connections main.o ./my_mat.so
#creating dynamic lib.a for recursion functions
libmy_mat.so: my_mat.o
	$(CC) -shared -o my_mat.so my_mat.o

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -fPIC -c my_mat.c

.PHONY:clean all
clean:
	rm -f *.o *.so connections
