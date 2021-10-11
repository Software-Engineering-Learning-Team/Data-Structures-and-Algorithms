#include <algorithm>
#include <cstring>
#include "BasicString.hpp"

BasicString::BasicString(const char *string) {
  if (string != nullptr) {
    length = std::strlen(string);
    this->string = new char[length + 1]();
    std::copy_n(string, length + 1, this->string);
  }
}

BasicString::BasicString(const BasicString &basicString) :
    BasicString(basicString.string) {}

BasicString::BasicString() : BasicString(nullptr) {}

BasicString::BasicString(BasicString &&basicString) noexcept: BasicString() {
  swap(*this, basicString);
}

BasicString::~BasicString() {
  delete[] string;
}

std::ostream &operator<<(std::ostream &stream, const BasicString &basicString) {
  stream << basicString.string;
  return stream;
}

BasicString &BasicString::operator=(BasicString &&other) noexcept {
  swap(*this, other);
  return *this;
}

BasicString &BasicString::operator=(BasicString other) {
  swap(*this, other);
  return *this;
}

void BasicString::swap(BasicString &lhs, BasicString &rhs) noexcept {
  std::swap(lhs.string, rhs.string);
  std::swap(lhs.length, rhs.length);
}

const char *BasicString::get_c_str() const {
  return string;
}
