prog: main.o input.o collision.o perso.o
	gcc main.o input.o collision.o perso.o -o prog -lSDL -lSDL_image -lSDL_mixer

main.o:main.c
	gcc -c main.c -g
input.o:input.c
	gcc -c input.c -g
collision.o:collision.c
	gcc -c collision.c -g
perso.o:perso.c
	gcc -c perso.c -g	