main: main.o log.o
	gcc -o main main.o log.o

main.o: main.c ../include/log.h
	gcc -Wall -g -I../include -c main.c -o main.o

log.o: ../src/log.c ../include/log.h
	gcc -Wall -g -I../include -c ../src/log.c -o log.o
clean:
	rm -f *.o