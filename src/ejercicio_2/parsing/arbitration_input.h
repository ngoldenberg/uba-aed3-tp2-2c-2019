#include <iostream>
#include <vector>
#include <tuple>
#include "ejercicio_2/config/constants.h"

using namespace std;

class ArbitrationInput {
 private:
  FloatMatrix multipliers_matrix_;
  int currencies_quantity_;
  void SetCurrenciesQuantity(int q);
  void SetMultipliersMatrix(FloatMatrix m);

 public:
  int GetCurrenciesQuantity() const;
  FloatMatrix const &GetMultipliersMatrix() const;
  static ArbitrationInput FromStreamParse(istream &input_stream);
  static vector<float> ReadLine(string line, int q);
  friend ostream &operator<<(ostream &os, const ArbitrationInput &a);
};
