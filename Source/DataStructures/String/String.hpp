#ifndef SOURCE_BASICSTRING_HPP
#define SOURCE_BASICSTRING_HPP

#include <cstddef>
#include <ostream>
#include "StringIterator.hpp"
namespace DataStructures {

struct String {

  String(const String &string);
  String(String &&string) noexcept;
  String &operator=(const String &other) noexcept;
  String &operator=(String &&other) noexcept;
  virtual ~String() noexcept;
  String();
  explicit String(const char *string);

  void reset();
  void clear();
  void reverse();
  void shrink_to_fit();

  [[nodiscard]] const char *get_c_str() const;
  [[nodiscard]] size_t get_capacity() const;
  [[nodiscard]] size_t get_length() const;
  [[nodiscard]] char get_first() const;
  [[nodiscard]] char get_last() const;
  [[nodiscard]] StringIterator begin() const;
  [[nodiscard]] StringIterator end() const;
  void reserve(std::size_t n);
  String get_reversed();

  [[nodiscard]] char operator[](std::size_t index) const;
  [[nodiscard]] char &operator[](std::size_t index);
  [[nodiscard]] char &at(std::size_t index);
  [[nodiscard]] char at(std::size_t index) const;

  [[nodiscard]] String get_slice(std::size_t first_index, std::size_t last_index) const;
  friend bool operator==(const String &first, const char *other_c_string) noexcept;
  friend bool operator!=(const String &first, const char *other_c_string) noexcept;
  friend bool operator==(const String &first, const String &second) noexcept;
  friend bool operator!=(const String &first, const String &second) noexcept;

  friend String operator+(const String &first, const char *c_string);
  String &operator+=(const char *c_string);

  friend String operator+(const String &first, const String &second);
  String &operator+=(const String &other);

  friend std::ostream &operator<<(std::ostream &stream, const String &basicString);

 private:
  char *string{};
  std::size_t string_length{};
  std::size_t capacity{};
  static void swap(String &first, String &second) noexcept;
};

}

#endif //SOURCE_BASICSTRING_HPP
