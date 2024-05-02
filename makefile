all:
	gcc -g -Wall life.c -o exec

run:
	./exec

clean:
	rm exec
