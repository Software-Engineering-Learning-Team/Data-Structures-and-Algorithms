#include <iostream>
#include <cstring>
#include <vector>
#include "DataStructures/String/String.hpp"

int main() {
  DataStructures::String string("Hello world!");
  std::cout << (string += " Wow!") << "\n";
  std::cout << string.get_capacity() << "\n";
  std::cout << string << "\n";
  DataStructures::String str2(":)");
  string += str2;
  std::cout << string << "\n";
  DataStructures::String new_string = string + " string";
  std::cout << string.get_capacity() << "\n";
  std::cout << new_string << " : " << new_string.get_capacity() << "\n";
  return 0;
}
