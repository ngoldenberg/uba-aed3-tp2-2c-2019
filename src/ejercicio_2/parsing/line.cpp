#include "parsing/line.h"

using namespace std;

istream& operator>>(istream &is, Line &l) {
  getline(is, l.data_);
  return is;
}

Line::operator string() const {
  return this->data_;
}
