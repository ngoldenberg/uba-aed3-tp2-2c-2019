import numpy as np
import matplotlib.pyplot as plt
# plt.style.use('seaborn-whitegrid')

def main():
	archivo_entrada = "entrada.txt"
	archivo_salida = "salida.txt"
	entrada = open(archivo_entrada, 'r')
	salida = open(archivo_salida, 'r')
	eje_x = []
	eje_y = []
	next(entrada)
	for line in entrada:
		eje_x.append(line[0])
		eje_y.append(line[2])
	entrada.close()
	clusters = []
	for line in salida:
		clusters.append(line[0])
	salida.close()
	plt.scatter(eje_x,eje_y,c=clusters,s=100)
	plt.show()
	return 

main()