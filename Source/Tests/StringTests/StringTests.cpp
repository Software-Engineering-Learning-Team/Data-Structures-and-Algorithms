#include <gtest/gtest.h>
#include <String/String.hpp>

TEST(StringTest, Constructor) {
  DataStructures::String string(nullptr);
  auto actual_length = string.get_length();
  std::size_t expected_length = 0;
  ASSERT_EQ(actual_length, expected_length);
}