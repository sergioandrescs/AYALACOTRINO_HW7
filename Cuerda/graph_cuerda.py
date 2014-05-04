from JSAnimation import HTMLWriter
from matplotlib import animation
from numpy import *
import matplotlib.pyplot as plt

#importo los datos iniciales para saber si comienzo bien
inicial = loadtxt('datos_iniciales.dat')
x = inicial[:,0]
uinicial = inicial[:,1]

#grafico estos datos
plt.plot(x,uinicial)
plt.title('$Grafica$ $inicial$')
plt.xlabel('$X$')
plt.ylabel('$Uinicial$')
plt.savefig('Grafica')

data = loadtxt('datos_cuerda.dat')

# create a simple animation
fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(-1, 1))
line, = ax.plot([], [], lw=2)

x = data[0,:]

def init():
   line.set_data([], [])
   return line,

def animate(i):
   line.set_data(x, data[i,:])
   return line,

anim = animation.FuncAnimation(fig, animate, init_func=init, frames=2000, interval=13)
plt.grid()
plt.show()
#anim.save('animation.html', writer=HTMLWriter(embed_frames=True))
