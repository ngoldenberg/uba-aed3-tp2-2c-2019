#include <fstream>
#include <gmock/gmock.h>
#include <string>
#include <vector>

#include "algorithms/BellmanFordAlgorithm.h"
#include "parsing/arbitration_input.h"
#include "config/constants.h"

using ::testing::Contains;
using ::testing::AllOf;
using ::testing::Property;

TEST(BellmanFord, 2_int_cycle) {
  std::ifstream input_file_stream(DATA_DIR + "ejercicio_2_-2_int_cycle.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);

  BellmanFordAlgorithm bfa;
  vector<int> cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {1, 2};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    std::cout << "EECTED CYCLE: " << expected_cycle[i] << " | cycle: " << cycle[i] << endl;
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

TEST(BellmanFord, 3_n_matrix) {
  std::ifstream input_file_stream(DATA_DIR + "ejercicio_2_-3_int_matrix.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  BellmanFordAlgorithm bfa;
  vector<int> cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {2, 3, 1};

  for (int i = 0; i < input.GetCurrenciesQuantity(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}

TEST(BellmanFord, all_1_matrix) {
  std::ifstream input_file_stream(DATA_DIR + "ejercicio_2_-3_int_matrix__all_1.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  BellmanFordAlgorithm bfa;

  vector<int> cycle;
  try {
    cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());
  } catch (logic_error) {
    ASSERT_EQ(cycle.size(), 0);
  }
}

TEST(BellmanFord, complex_samplex_1) {
  std::ifstream input_file_stream(DATA_DIR + "ejercicio_2_sample_1.txt", ios::in);
  ArbitrationInput input = ArbitrationInput::FromStreamParse(input_file_stream);
  BellmanFordAlgorithm bfa;
  vector<int> cycle = bfa.Solve(input.GetCurrenciesQuantity(), input.GetMultipliersMatrix());

  vector<int> expected_cycle = {17, 4};
  for (int i = 0; i < cycle.size(); i++) {
    ASSERT_EQ(cycle[i], expected_cycle[i]);
  }
}