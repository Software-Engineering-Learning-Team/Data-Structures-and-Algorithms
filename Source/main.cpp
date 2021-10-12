#include <iostream>
#include <cstring>
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

  DataStructures::String hello("Hello ");
  std::cout << hello << " : " << hello.get_capacity() << " : " << hello.get_length() << "\n";
  DataStructures::String helloHello = hello + DataStructures::String(", ") + DataStructures::String("World!");
  std::cout << helloHello << " : " << helloHello.get_capacity() << " : " << helloHello.get_length() << "\n";
  helloHello.shrink_to_fit();
  std::cout << helloHello << " : " << helloHello.get_capacity() << " : " << helloHello.get_length() << "\n";
  DataStructures::String hi("Hi");
  hi += ", ";
  hi += "World!";
  hi.shrink_to_fit();
  std::cout << hi << " : " << hi.get_capacity() << " : " << hi.get_length() << "\n";
  hi[1] = 'I';
  std::cout << hi << " : " << hi.get_capacity() << " : " << hi.get_length() << "\n";
  std::cout << hi[hi.get_length() - 1] << " : " << hi.get_capacity() << " : " << hi.get_length() << "\n";

  DataStructures::String str(nullptr);
  std::cout << str.get_first() << str.get_last() << "\n";
  str += "NEW";
  std::cout << str.get_first() << str.get_last() << "\n";
  str.at(1) = 'T';
  std::cout << str << "\n";
  str += " STRING FOR SLICING";
  std::cout << str << "\n";
  std::cout << "|" << str.get_slice(4, 9) << "|" << "\n";
  return 0;
}
