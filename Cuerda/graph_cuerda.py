from pylab import *
from numpy import *
from matplotlib import *
from matplotlib import animation
#from JSAnimation import HTMLWriter

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
ejes = plt.axes(xlim=(0, 1), ylim=(-1 , 1))
line, = ejes.plot([], [], lw=4, c='red')
title("$Animacion$ $de$ $cuerda$ $vibrando$")

#importo los datos para la animacion
data = loadtxt("datos_cuerda.dat");

def init():
    line.set_data([], [])
    return line,

def animate(i):
    global data
    x1 = linspace(0, 1, n)
    y = data[i,:]
    line.set_data(x1, y)
    return line,


animacion = animation.FuncAnimation(figura, animate, init_func=init, frames=10000, interval=20)

plt.grid()
plt.show()


