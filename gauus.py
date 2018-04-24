import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('datosgauss.txt')

minimo = data[:,0].min()
maximo = data[:,0].max()

i_x = data[data[:,0]==minimo, 1]
i_y = data[data[:,0]==minimo, 2]

f_x = data[data[:,0]==maximo, 1]
f_y = data[data[:,0]==maximo, 2]

plt.plot(i_x, i_y, label='inicial')
plt.plot(f_x, f_y, '--', label='final')
plt.legend()
plt.xlabel("x")
plt.ylabel("y")
plt.title('Grafica de Gauss')
plt.savefig('gauss.png')
plt.show()
