//
// Created by Christian nahuel Rivera on 6/10/19.
//

#include <utility>
#include <iostream>
#include <vector>
#include "../algoritmos/Segmentation.h"

std::vector<std::pair<int, int>> * input();

void print(std::vector<int> vector);

/*
 * Parametros de entrada:
 * - mstStrategy: define el algoritmo que usaremos para calcular el arbol generador mínimo en el grafo.
 * - depth: es la produndidad máxima con la que ejeturaremos la busqueda de vecinos para el eje inconsistente.
 * - sigmaT: representa la proporción en la que el peso del eje debe superar al promedio de ambos extremos.
 * - fT: es la proporción de ejes que superan el sigmaT.
 */
int main(){

    std::string mstStrategy;
    std::cin >> mstStrategy;

    int depth;
    std::cin >> depth;
    double sigmaT;
    std::cin >> sigmaT;
    double fT;
    std::cin >> fT;
    std::string poda;
    std::cin >> poda;

    std::vector<std::pair<int,int>>* dots = input();

    Segmentation segmentation = Segmentation(mstStrategy, poda);

    std::vector<int> outputDots = segmentation.execute(dots, depth, sigmaT, fT);

    print(outputDots);
    return 0;
}

void print(std::vector<int> dots) {
    for(int dot : dots){
        std::cout << dot << std::endl;
    }
}

std::vector<std::pair<int, int>> * input(){
    auto dots = new std::vector<std::pair<int,int>>();
    int size;
    std::cin >> size;

    int x, y;
    for(int iter = 0; iter < size; iter ++){
        std::cin >> x >> y;
        dots->emplace_back(x,y);
    }

    return dots;
}