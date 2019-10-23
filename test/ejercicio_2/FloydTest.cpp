#include <fstream>
#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "algorithms/FloydAlgorithm.h"
#include "parsing/arbitration_input.h"

using ::testing::Contains;
using ::testing::AllOf;
using ::testing::Property;

TEST(Floyd, 3_n_matrix) {
  std::ifstream input_file_stream("samples/ejercicio_2_-3_int_matrix.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  FloydAlgorithm fa;
  vector<int> cycle = fa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {5, 6, 1};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

TEST(Floyd, div_1) {
  std::ifstream input_file_stream("samples/div_1.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  FloydAlgorithm fa;
  vector<int> cycle = fa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {2, 1};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

