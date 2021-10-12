#include <algorithm>
#include <cstring>
#include <iostream>
#include "String.hpp"
#include "../../Algorithms/Copying.tpp"

namespace DataStructures {

String::String(const char *string) {
  if (string != nullptr) {
    std::size_t length = std::strlen(string);
    reserve(2 * length + 1);
    string_length = length;
    Algorithms::Copying::copy_data_into_array(this->string, string_length + 1, string);
  }
}

String::String(const String &basicString) :
    String(basicString.string) {}

String::String() : String(nullptr) {}

String::String(String &&basicString) noexcept: String(nullptr) {
  swap(*this, basicString);
}

String::~String() {
  reset();
}

std::ostream &operator<<(std::ostream &stream, const String &basicString) {
  stream << basicString.string;
  return stream;
}

String &String::operator=(String &&other) noexcept {
  swap(*this, other);
  return *this;
}

String &String::operator=(String other) {
  swap(*this, other);
  return *this;
}

void String::swap(String &lhs, String &rhs) noexcept {
  std::swap(lhs.string, rhs.string);
  std::swap(lhs.string_length, rhs.string_length);
  std::swap(lhs.capacity, rhs.capacity);
}

const char *String::get_c_str() const {
  return string;
}
void String::reserve(std::size_t n) {
  if (n > capacity) {
    char *temp = new char[n]();
    Algorithms::Copying::copy_data_into_array(temp, string_length, string);
    delete[] string;
    string = temp;
    capacity = n;
  }
}
void String::shrink_to_fit() {
  if (string_length + 1 != capacity) {
    char *temp = new char[string_length + 1]();
    Algorithms::Copying::copy_data_into_array(temp, string_length, string);
    delete[] string;
    string = temp;
    capacity = string_length + 1;
  }
}

size_t String::get_capacity() const {
  return capacity;
}
size_t String::get_length() const {
  return string_length;
}
void String::reset() {
  delete[] string;
  capacity = 0;
  string_length = 0;
  string = nullptr;
}
void String::clear() {
  Algorithms::Copying::fill_array(string, capacity, '\0');
}
StringIterator String::begin() const {
  return StringIterator(string);
}

StringIterator String::end() const {
  return StringIterator(string + string_length);
}

void String::reverse() {
  char *temp = new char[string_length + 1]();
  for (std::size_t i = 0; i < string_length; i++) {
    temp[i] = string[string_length - 1 - i];
  }
  delete[] string;
  string = temp;
}

String String::get_reversed() {
  String result(*this);
  result.reverse();
  return result;
}

}

