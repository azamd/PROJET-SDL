
prog:main.o dep.o
	gcc main.o dep.o -o prog -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -g
dep.o:dep.c
	gcc -c dep.c -lSDL -lSDL_image -g
