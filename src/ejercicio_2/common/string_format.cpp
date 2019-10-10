#include "string_format.h"

#include <sstream>
#include <iomanip>

std::string StringFormat::FillNumberDigits(int d) {
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << d;
  return ss.str();
}