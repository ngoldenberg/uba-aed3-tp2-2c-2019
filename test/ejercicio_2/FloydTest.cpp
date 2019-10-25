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

  vector<int> expected_cycle = {2, 3, 6};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

TEST(Floyd, all_1_matrix) {
  std::ifstream input_file_stream("samples/ejercicio_2_-3_int_matrix__all_1.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  FloydAlgorithm fa;

  vector<int> cycle;
  try {
    cycle = fa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());
  } catch(logic_error) {
    ASSERT_EQ(cycle.size(), 0);
  }
}

TEST(Floyd, 2_int_cycle) {
  std::ifstream input_file_stream("samples/ejercicio_2_-2_int_cycle.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  FloydAlgorithm fa;
  vector<int> cycle = fa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {1, 2};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

TEST(Floyd, div_1) {
  std::ifstream input_file_stream("samples/div_1.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  FloydAlgorithm fa;
  vector<int> cycle = fa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {1, 4, 5};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

