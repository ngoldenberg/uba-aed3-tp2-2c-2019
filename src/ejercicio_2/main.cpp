#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <stdlib.h>

#include "parsing/arbitration_input.h"
#include "algorithms/BellmanFordAlgorithm.h"
#include "algorithms/FloydAlgorithm.h"

using namespace std::chrono;

int main() {
  ArbitrationInput input = ArbitrationInput::FromStreamParse(cin);

  BellmanFordAlgorithm bfa;
  FloydAlgorithm fa;

  bool is_floyd = false;
  const char *floyd_env = getenv("FLOYD");

  if (floyd_env != nullptr) {
    is_floyd = *floyd_env != '0' && *floyd_env != 'f' && *floyd_env != 'F';
  }

  try {
    vector<int> cycle;
    if (is_floyd) {
      cycle = fa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());
    } else {
      cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());
    }
    cout << "SI ";
    for (int &vertex : cycle) {
      cout << vertex << " ";
    }
  } catch (logic_error) {
    cout << "NO" << endl;
  }

  return 0;
}
