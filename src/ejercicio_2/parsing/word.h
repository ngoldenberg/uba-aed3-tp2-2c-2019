#pragma once

#include <iostream>

using namespace std;

class Word {
 public:
  friend istream& operator>>(istream &is, Word &w);
  explicit operator string() const;
  explicit operator int() const;
  explicit operator float() const;

 private:
  string data_;
};
