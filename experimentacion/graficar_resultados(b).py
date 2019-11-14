from __future__ import division

import matplotlib.pyplot as plt
from matplotlib import colors as mcolors
# plt.style.use('seaborn-whitegrid')

def main():
	archivo_entrada = "entrada-100.txt"
	archivo_salida = "salida.txt"
	entrada = open(archivo_entrada, 'r')
	salida = open(archivo_salida, 'r')
	eje_x = []
	eje_y = []
	for i in range(5):
		next(entrada)
	for line in entrada:
		line = line.split()
		eje_x.append(line[0])
		eje_y.append(line[1])
	entrada.close()
	clusters = []
	for line in salida:
		clusters.append(line[0])
	salida.close()
	# plt.scatter(eje_x,eje_y,c=clusters,s=50,label=clusters)
	# plt.legend()
	# plt.show()

	# import matplotlib.pyplot as plt
	import matplotlib.patches as mpatches
	Y = [1, 1, 1, 2, 2, 2, 2]
	labels = [0, 1, 1, 0, 0, 1, 1]
	# key = {0: ('red', 'empty'), 1: ('green', 'full')}
	key = dict(mcolors.BASE_COLORS, **mcolors.CSS4_COLORS)
	print(key)
	i = 0
	plt.scatter(eje_x, eje_y, c=[key[index][0] for index in clusters], s=50)
	patches = [mpatches.Patch(color=color, label=label) for color, label in key.values()]
	plt.legend(handles=patches, labels=[label for _, label in key.values()], bbox_to_anchor=(1, .3))
	plt.show()



	return 

main()