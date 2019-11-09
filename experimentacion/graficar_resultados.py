import numpy as np
import matplotlib.pyplot as plt
from collections import Counter
# plt.style.use('seaborn-whitegrid')

def main():
	archivo_entrada = "entrada-5000.txt"
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
		line = line.split()
		clusters.append(line[0])
	salida.close()
	print (clusters)

	distinct_clusters = (Counter(clusters).keys())
	print(distinct_clusters)
	print(len(distinct_clusters))
	plt.scatter(eje_x,eje_y,c=clusters,s=50,label=len(distinct_clusters))
	plt.legend()
	plt.show()
	return 

main()