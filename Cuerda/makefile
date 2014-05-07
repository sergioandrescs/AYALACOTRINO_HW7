all : datos_cuerda.dat
	python graph_cuerda.py
datos_cuerda.dat : a.out
	./a.out
a.out : cuerda.c
	cc cuerda.c -lm
clean :  
	rm  *.dat a.out Grafica.png