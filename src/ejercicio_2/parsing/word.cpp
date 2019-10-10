#include "parsing/word.h"

using namespace std;

istream& operator>>(istream &is, Word &w) {
  getline(is, w.data_, ' ');
  return is;
}

Word::operator string() const {
  return this->data_;
}

Word::operator int() const {
  return std::stoi(this->data_);
}

Word::operator float() const {
  return std::stod(this->data_);
}
