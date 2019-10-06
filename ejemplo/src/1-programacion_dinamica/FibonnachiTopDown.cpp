//
// Created by Christian nahuel Rivera on 30/8/19.
//
#include <vector>

#include "FibonnachiTopDown.h"

unsigned long FibonnachiTopDown::execute(int number) {
    std::vector<unsigned long> results = std::vector<unsigned long>(number + 1, 0);
    return run(number,&results);
}

unsigned long FibonnachiTopDown::run(int number, std::vector<unsigned long> *results) {
    if(results->at(number) == 0){
        if(number == 0 || number == 1){
            results->at(number) = 1;
        } else {
           results->at(number) = run(number-1, results) + run(number-2, results);
        }
    }
    return results->at(number);
}
