from pylab import *
from numpy import *
from matplotlib import *
from matplotlib import animation

#Codigo de la animacion creado con ayuda del repositorio:
#http://jakevdp.github.io/

#importo los datos iniciales para saber si comienzo bien
inicial = loadtxt("datos_iniciales.dat")
x = inicial[:,0]
uinicial = inicial[:,1]

#grafico estos datos
plot(x,uinicial)
title("$Grafica$ $inicial$")
savefig("Grafica")

#procedimiento para la animacion
n = 1000
figura = plt.figure()
ejes = plt.axes(xlim=(0, 100), ylim=(-1 , 1))
line, = ejes.plot([], [], lw=4, c='red')
title("$Animacion$ $de$ $cuerda$ $vibrando$")

#importo los datos para la animacion
data = loadtxt("datos_cuerda.dat")
x1 = linspace(0,100,n)

def init():
    line.set_data([], [])
    return line,

def animate(i):
    y = data[i]
    line.set_data(x1, y)
    return line,


animacion = animation.FuncAnimation(figura, animate, init_func=init, frames=1000, interval=1)

plt.grid()
plt.show()


