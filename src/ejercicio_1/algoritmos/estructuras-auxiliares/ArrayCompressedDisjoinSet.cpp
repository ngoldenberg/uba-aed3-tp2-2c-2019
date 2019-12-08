//
// Created by Christian nahuel Rivera on 11/10/19.
//

#include "ArrayCompressedDisjoinSet.h"


void ArrayCompressedDisjoinSet::create(Graph *graph) {
    std::vector<int> components;
    std::vector<int> heights;
    components.resize(graph->getVertex());
    heights.resize(graph->getVertex());
    for(std::size_t index = 0; index < components.size(); index++){
        components.at(index) = index;
        heights.at(index) = 1;
    }
    this->components = components;
    this->heights = heights;
}


int ArrayCompressedDisjoinSet::find(int vertex) {
    // Si soy hijo, voy a buscar a mi padre y actualizo
    if( this->components.at(vertex) != vertex){
        this->components.at(vertex) = find(this->components.at(vertex));
    }
    return this->components.at(vertex);
}

void ArrayCompressedDisjoinSet::join(int alreadyIn, int newNode) {
    int lRepresentative = find(alreadyIn);
    int rRepresentative = find(newNode);

    if(heights.at(lRepresentative) < heights.at(rRepresentative)){
        this->components.at(lRepresentative) = rRepresentative;
    }else{
        this->components.at(rRepresentative) = lRepresentative;
    }
    if(heights.at(lRepresentative) == heights.at(rRepresentative)) {
        this->heights.at(rRepresentative) = this->heights.at(rRepresentative) + 1;
    }
}