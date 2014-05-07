all: proba.dat
	python animacion.py
proba.dat: a.out
	./a.out
a.out: Schroedinger.c
	cc Schroedinger.c -lm
clean:
	rm *.dat a.out
