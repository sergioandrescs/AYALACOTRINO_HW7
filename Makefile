schroe.dat : a.out
	rm -f schroe.dat
	./a.out > schroe.dat
a.out : schroe.c
	cc schroe.c -lm 
all : schroe.dat
	python animate.py
clear:
	rm ./a.out schroe.dat
