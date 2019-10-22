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

  try {
    vector<int> cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());
    cout << "SI ";
    for (int &vertex : cycle)
    {
      cout << vertex << " ";
    }
  } catch(logic_error) {
    cout << "NO" << endl;
  }


  return 0;
}
