graph_onda.py : data.dat
	python graph_cuerda.py
data.dat : a.out
	./a.out
a.out : cuerda.c
	cc cuerda.c -lm
clean :  
	rm  data.dat a.out