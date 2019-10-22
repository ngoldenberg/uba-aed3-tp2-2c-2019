#include <fstream>
#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "algorithms/BellmanFordAlgorithm.h"
#include "parsing/arbitration_input.h"

using ::testing::Contains;
using ::testing::AllOf;
using ::testing::Property;

TEST(BellmanFord, 2_int_cycle) {
  std::ifstream input_file_stream("samples/ejercicio_2_-2_int_cycle.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  BellmanFordAlgorithm bfa;
  vector<int> cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {2, 1};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

TEST(BellmanFord, 3_n_matrix) {
  std::ifstream input_file_stream("samples/ejercicio_2_-3_int_matrix.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  BellmanFordAlgorithm bfa;
  vector<int> cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {2, 3, 1};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}