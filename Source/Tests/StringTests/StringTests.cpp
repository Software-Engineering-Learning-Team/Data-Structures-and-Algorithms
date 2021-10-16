#include <gtest/gtest.h>
#include <String/String.hpp>

TEST(StringTest, ConstructorOfEmptyString) {
  DataStructures::String string_with_nullptr(nullptr);
  DataStructures::String string_with_no_parameters;
  DataStructures::String string_with_empty_string("");
  std::size_t expected_length = 0;

  ASSERT_EQ(string_with_nullptr.get_length(), expected_length);
  ASSERT_EQ(string_with_no_parameters.get_length(), expected_length);
  ASSERT_EQ(string_with_empty_string.get_length(), expected_length);

  ASSERT_EQ(string_with_nullptr.get_capacity(), 1);
  ASSERT_EQ(string_with_no_parameters.get_capacity(), 1);
  ASSERT_EQ(string_with_empty_string.get_capacity(), 1);
}

TEST(StringTest, ConstructorFromCString) {
  DataStructures::String string("Hello, World!");

  ASSERT_EQ(string.get_length(), 13);
  ASSERT_EQ(string.get_capacity(), 14);
}

TEST(StringTest, ConstructorFromDifferentStrings) {
  DataStructures::String string("Hello!");
  const DataStructures::String &string_copy(string);

  ASSERT_EQ(string, string_copy);
  ASSERT_EQ(string.get_capacity(), string_copy.get_capacity());
  ASSERT_EQ(string.get_capacity(), 7);
}

TEST(StringTest, AppendToString) {
  DataStructures::String string("Hello!");
  string += " And bye!";

  ASSERT_TRUE(string == "Hello! And bye!");
  ASSERT_EQ(string.get_capacity(), 23);

  string += DataStructures::String(" :)");

  ASSERT_TRUE(string == "Hello! And bye! :)");
  ASSERT_EQ(string.get_capacity(), 23);
}