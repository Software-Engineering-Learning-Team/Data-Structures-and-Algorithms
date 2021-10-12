#include <iostream>
#include "DataStructures/String/String.hpp"

int main() {
  String string("Hello world!");
  std::cout << string << " : " << string.get_capacity() << " : " << string.get_length() << "\n";
  string = string;
  string.shrink_to_fit();
  std::cout << string << " : " << string.get_capacity() << " : " << string.get_length() << "\n";
  String string1{std::move(string)};
  std::cout << string1 << " : " << string1.get_capacity() << " : " << string1.get_length() << "\n";
  std::cout << String("").get_length() << "\n";
  return 0;
}
