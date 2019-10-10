#pragma once

#include <iostream>

using namespace std;

class Line {
 public:
  friend istream& operator>>(istream &is, Line &l);
  operator string() const;

 private:
  string data_;
};
