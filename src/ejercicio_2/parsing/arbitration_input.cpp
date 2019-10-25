#include <iterator>
#include <sstream>
#include <tuple>

#include "arbitration_input.h"
#include "common/string_format.h"
#include "line.h"
#include "word.h"
#include "../config/constants.h"

using namespace std;

vector<float> ArbitrationInput::ReadLine(string line, int q) {
  stringstream line_stream(line);
  istream_iterator<Word> word_it = istream_iterator<Word>(line_stream);

  vector<float> parsed_line(q);

  for (int i = 0; i < q; i++) {
    parsed_line[i] = (float) *word_it;
    ++word_it;
  }

  return parsed_line;
}

ArbitrationInput ArbitrationInput::FromStreamParse(istream &input_stream) {
  ArbitrationInput arbitration_input;

  istream_iterator<Line> eol;
  istream_iterator<Line> line_it = istream_iterator<Line>(input_stream);

  stringstream line_stream((string) * line_it);
  istream_iterator<Word> word_it = istream_iterator<Word>(line_stream);

  arbitration_input.SetCurrenciesQuantity((int) *word_it);

  FloatMatrix matrix(arbitration_input.GetCurrenciesQuantity());

  int line_index = 0;
  while (line_it != eol && line_index < arbitration_input.GetCurrenciesQuantity()) {
    ++line_it;
    matrix[line_index] = ReadLine((string) * line_it, arbitration_input.GetCurrenciesQuantity());
    ++line_index;
  }

  arbitration_input.SetMultipliersMatrix(matrix);
  return arbitration_input;
}

int ArbitrationInput::GetCurrenciesQuantity() const {
  return currencies_quantity_;
}

const FloatMatrix &ArbitrationInput::GetMultipliersMatrix() const {
  return multipliers_matrix_;
}

ostream &operator<<(ostream &os, const ArbitrationInput &a) {
  StringFormat sf;
  os << "- Quantity: " << sf.FillNumberDigits(a.currencies_quantity_) << "\n";
  os << "- Currencies matrix: \n";

  for (int i = 0; i < a.currencies_quantity_; i++) {
    for (int j = 0; j < a.currencies_quantity_; j++) {
      os << a.multipliers_matrix_[i][j] << " ";
    }
    os << "\n";
  }

  return os;
}
void ArbitrationInput::SetCurrenciesQuantity(int q) {
  currencies_quantity_ = q;
}
void ArbitrationInput::SetMultipliersMatrix(FloatMatrix m) {
  multipliers_matrix_ = m;
}
