#include <gtest/gtest.h>
#include <String/String.hpp>
#include <cstring>

TEST(StringTest, ConstructorOfEmptyString)
{
	DataStructures::String string_with_nullptr(nullptr);
	DataStructures::String string_with_no_parameters;
	DataStructures::String string_with_empty_string("");

	ASSERT_EQ(string_with_nullptr.get_length(), 0);
	ASSERT_EQ(string_with_no_parameters.get_length(), 0);
	ASSERT_EQ(string_with_empty_string.get_length(), 0);

	ASSERT_EQ(string_with_nullptr.get_capacity(), 1);
	ASSERT_EQ(string_with_no_parameters.get_capacity(), 1);
	ASSERT_EQ(string_with_empty_string.get_capacity(), 1);
}

TEST(StringTest, ConstructorFromCString)
{
	DataStructures::String string("Hello, World!");

	ASSERT_EQ(string.get_length(), 13);
	ASSERT_EQ(string.get_capacity(), 14);
}

TEST(StringTest, ConstructorFromDifferentStrings)
{
	DataStructures::String string("Hello!");
	const DataStructures::String& string_copy(string);

	ASSERT_EQ(string, string_copy);
	ASSERT_EQ(string.get_capacity(), string_copy.get_capacity());
	ASSERT_EQ(string.get_capacity(), 7);
}

TEST(StringTest, AppendToString)
{
	DataStructures::String string("Hello!");
	string += " And bye!";

	ASSERT_TRUE(string == "Hello! And bye!");
	ASSERT_EQ(string.get_capacity(), 23);
	ASSERT_EQ(string.get_length(), 15);

	string += DataStructures::String(" :)");

	ASSERT_EQ(string, "Hello! And bye! :)");
	ASSERT_EQ(string.get_capacity(), 23);
	ASSERT_EQ(string.get_length(), 18);

	string += string;
	ASSERT_EQ(string, "Hello! And bye! :)Hello! And bye! :)");

	ASSERT_NE(string.get_capacity(), string.get_length() + 1);
	string.shrink_to_fit();
	ASSERT_EQ(string.get_capacity(), string.get_length() + 1);
}

TEST(StringTest, ReverseFunctions)
{
	DataStructures::String string("Hello, World!");

	ASSERT_EQ(string.get_reversed(), "!dlroW ,olleH");
	ASSERT_EQ(string, "Hello, World!");

	string += "!";

	ASSERT_EQ(string.get_reversed(), "!!dlroW ,olleH");
	ASSERT_EQ(string, "Hello, World!!");

	string.reverse();

	ASSERT_EQ(string, "!!dlroW ,olleH");
	ASSERT_EQ(string.get_reversed(), "Hello, World!!");
}

TEST(StringTest, Slice)
{
	DataStructures::String string("Hello, World string for testing slice!");

	ASSERT_EQ(string.get_slice(0, 4), "Hello");
	ASSERT_EQ(string.get_slice(7, 11), "World");
	ASSERT_EQ(string.get_slice(13, 37), "string for testing slice!");
	ASSERT_EQ(string, "Hello, World string for testing slice!");
}

TEST(StringTest, Indexes)
{
	DataStructures::String string("Indexes testing");
	const DataStructures::String const_string("Indexes testing");

	ASSERT_EQ(string[0], 'I');
	ASSERT_EQ(string[string.get_length() - 1], 'g');

	ASSERT_EQ(string.get_first(), 'I');
	ASSERT_EQ(string.get_last(), 'g');

	ASSERT_EQ(string[8], 't');
	ASSERT_EQ(string[12], 'i');

	ASSERT_EQ(const_string[8], string[8]);
	ASSERT_EQ(const_string.at(8), string[8]);

	string[8] = 'T';
	ASSERT_EQ(string, "Indexes Testing");

	string.at(8) = 't';
	ASSERT_EQ(string, "Indexes testing");

	ASSERT_THROW(string.at(string.get_length()), std::out_of_range);
	ASSERT_THROW(const_string.at(const_string.get_length()), std::out_of_range);
}

TEST(StringTest, CyclesAndIterators)
{
	DataStructures::String string("Cycles and iterators testing");

	std::size_t i = 0;
	for (const auto& letter: string)
	{
		ASSERT_EQ(letter, string[i++]);
	}

	for (auto& letter: string)
	{
		letter = '_';
	}

	ASSERT_EQ(string, "____________________________");
}

TEST(StringTest, Concatenation)
{
	DataStructures::String string1("Very");
	DataStructures::String string2("Test");

	DataStructures::String result = string1 + " important " + string2;

	ASSERT_EQ(result, "Very important Test");
}

TEST(StringTest, EqualsAndNotEquals)
{
	DataStructures::String string1("Yes");
	DataStructures::String string2("yeS");
	DataStructures::String string3("no");

	ASSERT_TRUE(string1 == "Yes");
	ASSERT_TRUE(string1 == string1);
	ASSERT_TRUE(string1 == DataStructures::String("Yes"));

	ASSERT_TRUE(string2 != "Yes");
	ASSERT_TRUE(string2 != string1);
	ASSERT_TRUE(string2 != DataStructures::String("Yes"));

	ASSERT_TRUE(string2 != string3);
}

TEST(StringTest, MoveSematics)
{
	DataStructures::String string1("Yes");
	DataStructures::String string2("No");
	string2 = std::move(string1);

	ASSERT_EQ(string2, "Yes");

	DataStructures::String string3(std::move(string2));

	ASSERT_EQ(string3, "Yes");
}

TEST(StringTest, CopyAssignment)
{
	DataStructures::String string1("Yes");
	DataStructures::String string2("No");
	string2 = string1;

	ASSERT_EQ(string1, string2);
	ASSERT_STREQ(string1.get_c_str(), string2.get_c_str());
}

TEST(StringTest, ResetAndClear)
{
	DataStructures::String string("Reset and clear");
	string.clear();

	ASSERT_EQ(string, "");
	ASSERT_EQ(string.get_capacity(), 16);

	string.reset();

	ASSERT_EQ(string, "");
	ASSERT_EQ(string.get_capacity(), 1);
}

TEST(StringTest, StringToOstream)
{
	DataStructures::String string("String for output");
	std::ostringstream stream;
	stream << string;

	ASSERT_TRUE(stream.str() == "String for output");
}

TEST(StringTest, ReadStringFromStream)
{
	DataStructures::String string;
	std::istringstream stream("Hello from input stream\n");
	stream >> string;
	ASSERT_TRUE(string == "Hello from input stream");

	stream.setstate(std::ios::failbit);
	string.clear();
	stream >> string;
	ASSERT_TRUE(string == "");
}