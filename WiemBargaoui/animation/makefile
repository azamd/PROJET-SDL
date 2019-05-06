test:main.o animation.o
	gcc   main.o animation.o -o test -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm
main.o:main.c
	gcc -c main.c -g

animation.o:animation.c
	gcc -c animation.c -g 