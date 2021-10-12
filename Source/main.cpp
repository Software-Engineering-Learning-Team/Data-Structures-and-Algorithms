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
  std::cout << string1.get_reversed() << " : " << string1.get_capacity() << " : " << string1.get_length() << "\n";
  std::cout << string1 << " : " << string1.get_capacity() << " : " << string1.get_length() << "\n";

  for (const auto &c: string1) {
    std::cout << c << " ";
  }
  std::cout << "\n";

  if ((string1.get_reversed() == DataStructures::String("!dlrow olleH"))) {
    std::cout << "Equal!\n";
  } else {
    std::cout << "Not equal!\n";
  }
  string1.clear();
  string1.reset();
  std::cout << string1 << " : " << string1.get_capacity() << " : " << string1.get_length() << "\n";
  return 0;
}
