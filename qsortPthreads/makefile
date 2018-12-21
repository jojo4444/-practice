all: sort

sort: main.o cmpf.o
	gcc main.o cmpf.o -o sort

main.o: main.c
	gcc -c -pthread main.c

cmpf.o: cmpf.c
	gcc -c cmpf.c

clean:
	rm -rf *.o sort
