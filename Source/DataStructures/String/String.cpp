#include <utility>
#include <cstring>
#include <iostream>
#include "String.hpp"
#include "../../Algorithms/Copying/Copying.tpp"

namespace DataStructures {

String::String(const String &string) :
    String(string.string) {}

String::String(String &&string) noexcept {
  swap(*this, string);
}

String &String::operator=(const String &other) noexcept {
  *this = String(other);
  return *this;
}

String &String::operator=(String &&other) noexcept {
  swap(*this, other);
  return *this;
}

String::~String() noexcept {
  delete[] string;
}

String::String() : String(nullptr) {}

String::String(const char *string) {
  this->string = new char[1]();
  this->capacity = 1;
  if (string != nullptr) {
    std::size_t length = std::strlen(string);
    reserve(length + 1);
    string_length = length;
    Algorithms::Copying::copy_data_into_array(this->string, string_length + 1, string);
  }
}

void String::reset() {
  delete[] string;
  capacity = 1;
  string_length = 0;
  string = new char[1]();
}

void String::clear() {
  Algorithms::Copying::fill_array(string, capacity, '\0');
  string_length = 0;
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

const char *String::get_c_str() const {
  return string;
}

size_t String::get_capacity() const {
  return capacity;
}

size_t String::get_length() const {
  return string_length;
}

char String::get_first() const {
  return string[0];
}

char String::get_last() const {
  return string[string_length != 0 ? string_length - 1 : 0];
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

char &String::operator[](std::size_t index) {
  return string[index];
}

char String::operator[](std::size_t index) const {
  return string[index];
}

char &String::at(std::size_t index) {
  if (index >= string_length) {
    throw std::out_of_range("String index is out of range!");
  }
  return string[index];
}

char String::at(std::size_t index) const {
  if (index >= string_length) {
    throw std::out_of_range("String index is out of range!");
  }
  return string[index];
}

String String::get_slice(std::size_t first_index, std::size_t last_index) const {
  String result;
  result.reserve(last_index - first_index + 2);
  Algorithms::Copying::copy_data_into_array(result.string,
                                            last_index - first_index + 1,
                                            string + first_index);
  return result;
}

bool operator==(const String &first, const char *other_c_string) noexcept {
  if (first.string_length == std::strlen(other_c_string)) {
    for (std::size_t i = 0; i < first.string_length; i++) {
      if (first.string[i] != other_c_string[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool operator!=(const String &first, const char *other_c_string) noexcept {
  return !(first == other_c_string);
}

bool operator==(const String &first, const String &second) noexcept {
  return first == second.string;
}

bool operator!=(const String &first, const String &second) noexcept {
  return !(first == second);
}

String operator+(const String &first, const char *c_string) {
  String result;
  std::size_t c_string_length = std::strlen(c_string);
  std::size_t sum_length = first.string_length + c_string_length;
  result.reserve(sum_length + 1);
  Algorithms::Copying::copy_data_into_array(result.string, first.string_length, first.string);
  Algorithms::Copying::copy_data_into_array(result.string + first.string_length,
                                            c_string_length, c_string);
  result.string_length = sum_length;
  return result;
}

String &String::operator+=(const char *c_string) {
  std::size_t c_string_length = std::strlen(c_string);
  std::size_t new_length = string_length + c_string_length;
  if (new_length + 1 > capacity) {
    reserve(static_cast<std::size_t>(1.5 * static_cast<double>(new_length)) + 1);
  }
  Algorithms::Copying::copy_data_into_array(string + string_length, std::strlen(c_string), c_string);
  string_length = new_length;
  return *this;
}

String operator+(const String &first, const String &second) {
  return first + second.string;
}

String &String::operator+=(const String &other) {
  *this += other.string;
  return *this;
}

std::ostream &operator<<(std::ostream &stream, const String &basicString) {
  if (basicString.string != nullptr) {
    stream << basicString.string;
  }
  return stream;
}

void String::swap(String &first, String &second) noexcept {
  std::swap(first.string, second.string);
  std::swap(first.string_length, second.string_length);
  std::swap(first.capacity, second.capacity);
}

}

