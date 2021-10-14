#include <gtest/gtest.h>
#include <String/String.hpp>

TEST(StringTest, Constructor_with_nullptr) {
  DataStructures::String string(nullptr);
  auto actual_length = string.get_length();
  std::size_t expected_length = 0;
  ASSERT_EQ(actual_length, expected_length);
}

TEST(StringTest, Constructor_with_empty_string) {
  DataStructures::String string("");
  auto actual_length = string.get_length();
  std::size_t expected_length = 0;
  ASSERT_EQ(actual_length, expected_length);
}

TEST(StringTest, Constructor_with_correct_string) {
    DataStructures::String string("Hello!");
    auto actual_length = string.get_length();
    std::size_t expected_length = 6;
    ASSERT_EQ(actual_length, expected_length);
}