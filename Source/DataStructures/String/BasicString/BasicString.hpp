#ifndef SOURCE_BASICSTRING_HPP
#define SOURCE_BASICSTRING_HPP

#include <cstddef>
#include <ostream>

struct BasicString {
  BasicString();
  explicit BasicString(const char *string);
  BasicString(const BasicString &basicString);
  BasicString(BasicString &&basicString) noexcept;
  ~BasicString();

  BasicString &operator=(BasicString other);
  BasicString &operator=(BasicString &&other) noexcept;

  friend std::ostream &operator<<(std::ostream &stream, const BasicString &basicString);

  [[nodiscard]] const char *get_c_str() const;

 private:
  std::size_t length{};
  char *string{};
  static void swap(BasicString &lhs, BasicString &rhs) noexcept;
};

#endif //SOURCE_BASICSTRING_HPP
