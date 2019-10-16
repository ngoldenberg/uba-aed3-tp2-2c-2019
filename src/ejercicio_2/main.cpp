#include <iostream>
#include <iterator>

#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include <chrono>

#include "parsing/arbitration_input.h"
#include "algorithms/BellmanFordAlgorithm.h"

using namespace std::chrono;

int main() {

  ArbitrationInput input = ArbitrationInput::FromStreamParse(cin);

  // TODO: if Bellman-Ford or Floyd-Warshal -> algorithm

  BellmanFordAlgorithm bfa;

  cout << bfa->CycleExists(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix(), 1) << endl;

  // Cantidad de divisas diferentes: input.GetCurrenciesQuantity()
  // Matriz c: input.GetMultipliersMatrix()

  // Podemos hacer cout de nuesto input directamente por si necesitamos debuggear
  cout << input << endl;


  return 0;
}
