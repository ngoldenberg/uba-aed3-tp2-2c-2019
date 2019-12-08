//
// Created by Christian nahuel Rivera on 8/12/19.
//

#include <utility>
#include <iostream>
#include <vector>
#include "../algoritmos/Segmentation.h"

std::vector<std::pair<int, int>> * input();

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

    // tomo tiempos
    auto start = std::chrono::steady_clock::now();
    std::vector<int> outputDots = segmentation.execute(dots, depth, sigmaT, fT);
    auto end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
    return 0;
}

std::vector<std::pair<int, int>> * input() {
    auto dots = new std::vector<std::pair<int, int>>();
    int size;
    std::cin >> size;

    int x, y;
    for (int iter = 0; iter < size; iter++) {
        std::cin >> x >> y;
        dots->emplace_back(x, y);
    }

    return dots;
}