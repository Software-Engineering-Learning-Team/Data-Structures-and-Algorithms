#ifndef SOURCE_BASICSTRING_HPP
#define SOURCE_BASICSTRING_HPP

#include <cstddef>
#include <ostream>
#include "StringIterator.hpp"
namespace DataStructures {

struct String {
  String();
  explicit String(const char *string);
  String(const String &basicString);
  String(String &&basicString) noexcept;
  ~String();

  String &operator=(String other);
  String &operator=(String &&other) noexcept;

  friend std::ostream &operator<<(std::ostream &stream, const String &basicString);

  void reserve(std::size_t n);
  void shrink_to_fit();

  void reset();
  void clear();

  void reverse();
  String get_reversed();

  [[nodiscard]] const char *get_c_str() const;
  [[nodiscard]] size_t get_capacity() const;
  [[nodiscard]] size_t get_length() const;

  [[nodiscard]] StringIterator begin() const;
  [[nodiscard]] StringIterator end() const;

 private:
  std::size_t string_length{};
  std::size_t capacity{};
  char *string{};
  static void swap(String &lhs, String &rhs) noexcept;
};

}

#endif //SOURCE_BASICSTRING_HPP
