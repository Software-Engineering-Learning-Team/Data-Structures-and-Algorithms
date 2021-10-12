#include <iostream>
#include "DataStructures/String/String.hpp"


int main() {
  DataStructures::String string("Hello world!");
  std::cout << string << " : " << string.get_capacity() << " : " << string.get_length() << "\n";
  string = string;
  string.shrink_to_fit();
  std::cout << string << " : " << string.get_capacity() << " : " << string.get_length() << "\n";
  DataStructures::String string1{std::move(string)};
  std::cout << string1 << " : " << string1.get_capacity() << " : " << string1.get_length() << "\n";
  std::cout << DataStructures::String("").get_length() << "\n";

  for (const auto &c: string1) {
    std::cout << c << "\t";
  }
  std::cout << "\n";
  return 0;
}
