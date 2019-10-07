//
// Created by Christian nahuel Rivera on 6/10/19.
//

#include <utility>
#include <iostream>
#include <vector>
#include "../algoritmos/Segmentation.h"

std::vector<std::pair<int, int>> * input();

void print(std::vector<int> vector);

int main(){
    std::string mstStrategy;
    std::cin >> mstStrategy;

    std::vector<std::pair<int,int>>* dots = input();

    Segmentation segmentation = Segmentation(mstStrategy);

    std::vector<int> outputDots = segmentation.execute(*dots);

    print(outputDots);
}

void print(std::vector<int> dots) {
    for(int dot : dots){
        std::cout << dot;
    }
}

std::vector<std::pair<int, int>> * input(){
    std::vector<std::pair<int,int>> dots;
    int size;
    std::cin >> size;

    int x, y;
    for(int iter = 0; iter < size; iter ++){
        std::cin >> x >> y;
        dots.emplace_back(x,y);
    }

    return &dots;
}