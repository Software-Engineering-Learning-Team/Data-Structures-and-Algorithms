#include <iostream>
#include "DataStructures/String/BasicString/BasicString.hpp"

int main() {
  BasicString basicString("Hello world!");
  std::cout << basicString << "\n";
  basicString = basicString;
  std::cout << basicString << "\n";
  BasicString basicString1{std::move(basicString)};
  std::cout << basicString1 << "\n";
  return 0;
}
