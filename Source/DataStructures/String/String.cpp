#include <algorithm>
#include <cstring>
#include <iostream>
#include "String.hpp"
#include "../../Algorithms/Copying/Copying.tpp"

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
  if (basicString.string != nullptr) {
    stream << basicString.string;
  }
  return stream;
}

String &String::operator=(String other) noexcept {
  swap(*this, other);
  return *this;
}

void String::swap(String &first, String &second) noexcept {
  std::swap(first.string, second.string);
  std::swap(first.string_length, second.string_length);
  std::swap(first.capacity, second.capacity);
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
bool operator==(const String &first, const String &second) noexcept {
  if (first.string_length == second.string_length && first.string_length > 0) {
    for (std::size_t i = 0; i < first.string_length; i++) {
      if (first.string[i] != second.string[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}
bool operator!=(const String &first, const String &second) noexcept {
  return !(first == second);
}
String operator+(const String &first, const String &second) {
  String result;
  std::size_t sum_length = first.string_length + second.string_length;
  result.reserve(2 * sum_length + 1);
  char *first_string_end_ptr =
      Algorithms::Copying::copy_data_into_array(result.string, first.string_length, first.string);
  Algorithms::Copying::copy_data_into_array(first_string_end_ptr, second.string_length, second.string);
  result.string_length = sum_length;
  return result;
}
String &String::operator+=(const String &other) {
  *this = *this + other;
  return *this;
}
String operator+(const String &first, const char *string) {
  const String &result(first);
  return result + String(string);
}
String &String::operator+=(const char *string) {
  *this = *this + string;
  return *this;
}

}

