from JSAnimation import HTMLWriter
from matplotlib import animation
import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt('data.dat')

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

anim = animation.FuncAnimation(fig, animate, init_func=init,
                        frames=2000, interval=13, blit=True)
plt.grid()
plt.show()
#anim.save('animation.html', writer=HTMLWriter(embed_frames=True))
