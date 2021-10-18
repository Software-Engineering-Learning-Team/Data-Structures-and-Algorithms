#ifndef SOURCE_BASICSTRING_HPP
#define SOURCE_BASICSTRING_HPP

#include <cstddef>
#include <ostream>
#include "StringIterator.hpp"
namespace DataStructures {

/// String class.
struct String {

  /// Copy constructor.
  String(const String &string);

  /// Move constructor.
  String(String &&string) noexcept;

  /// Copy assignment operator.
  String &operator=(const String &other);

  /// Move assignment operator.
  String &operator=(String &&other) noexcept;

  /// Virtual destructor.
  virtual ~String() noexcept;

  /// Default constructs. Initializes empty string.
  String();

  /// Constructor from C string.
  /// \param string String for constructing from.
  explicit String(const char *string);

  /// Resets the string completely.
  /// After this sting will be really empty with capacity of 1 and length 0.
  void reset();

  /// Clears the string. Capacity remains unchanged, but length will be 0.
  void clear();

  ///  Reserves memory (dynamic) for n string symbols.
  /// \param n Number of string symbols to reserve memory for.
  /// \remark If n &le capacity then nothing happens.
  /// Otherwise new memory is allocated and raw_string is being copied to new location.
  void reserve(std::size_t n);

  /// Reduces capacity to length + 1.
  void shrink_to_fit();

  [[nodiscard]] const char *get_c_str() const;
  [[nodiscard]] size_t get_capacity() const;
  [[nodiscard]] size_t get_length() const;
  [[nodiscard]] char get_first() const;
  [[nodiscard]] char get_last() const;
  [[nodiscard]] StringIterator begin() const;
  [[nodiscard]] StringIterator end() const;

  void reverse();
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
  char *raw_string{};
  std::size_t string_length{};
  std::size_t capacity{};
  static void swap(String &first, String &second) noexcept;
};

}

#endif //SOURCE_BASICSTRING_HPP
