#include <utility>
#include <cstring>
#include <iostream>
#include "String.hpp"
#include "../../Algorithms/Copying/Copying.tpp"

namespace DataStructures
{

	String::String(const String& string) :
			String(string.raw_string)
	{
	}

	String::String(String&& string) noexcept
	{
		swap(*this, string);
	}

	String& String::operator=(const String& other)
	{
		*this = String(other);
		return *this;
	}

	String& String::operator=(String&& other) noexcept
	{
		swap(*this, other);
		return *this;
	}

	String::~String() noexcept
	{
		delete[] raw_string;
	}

	String::String() : String(nullptr)
	{
	}

	String::String(const char* string)
	{
		this->raw_string = new char[1]();
		this->capacity = 1;
		if (string != nullptr)
		{
			std::size_t length = std::strlen(string);
			reserve(length + 1);
			string_length = length;
			Algorithms::Copying::copy_data_into_array(this->raw_string, string_length + 1, string);
		}
	}

	void String::reset()
	{
		delete[] raw_string;
		capacity = 1;
		string_length = 0;
		raw_string = new char[1]();
	}

	void String::clear()
	{
		Algorithms::Copying::fill_array(raw_string, capacity, '\0');
		string_length = 0;
	}

	void String::reserve(std::size_t n)
	{
		if (n > capacity)
		{
			char* temp = new char[n]();
			Algorithms::Copying::copy_data_into_array(temp, string_length, raw_string);
			delete[] raw_string;
			raw_string = temp;
			capacity = n;
		}
	}

	const char* String::get_c_str() const
	{
		return raw_string;
	}

	size_t String::get_capacity() const
	{
		return capacity;
	}

	size_t String::get_length() const
	{
		return string_length;
	}

	char String::get_first() const
	{
		return raw_string[0];
	}

	char String::get_last() const
	{
		return raw_string[string_length != 0 ? string_length - 1 : 0];
	}

	StringIterator String::begin() const
	{
		return StringIterator(raw_string);
	}

	StringIterator String::end() const
	{
		return StringIterator(raw_string + string_length);
	}

	void String::reverse()
	{
		for (std::size_t i = 0; i < string_length / 2; i++)
		{
			std::swap(raw_string[string_length - i - 1], raw_string[i]);
		}
	}

	String String::get_reversed() const
	{
		String result(*this);
		result.reverse();
		return result;
	}

	char& String::operator[](std::size_t index)
	{
		return raw_string[index];
	}

	char String::operator[](std::size_t index) const
	{
		return raw_string[index];
	}

	char& String::at(std::size_t index)
	{
		if (index >= string_length)
		{
			throw std::out_of_range("String index is out of range!");
		}
		return raw_string[index];
	}

	char String::at(std::size_t index) const
	{
		if (index >= string_length)
		{
			throw std::out_of_range("String index is out of range!");
		}
		return raw_string[index];
	}

	String String::get_slice(std::size_t first_index, std::size_t last_index) const
	{
		String result;
		result.reserve(last_index - first_index + 2);
		Algorithms::Copying::copy_data_into_array(result.raw_string,
				last_index - first_index + 1,
				raw_string + first_index);
		result.string_length = last_index - first_index + 1;
		return result;
	}

	bool operator==(const String& first, const char* other_c_string) noexcept
	{
		if (first.string_length == std::strlen(other_c_string))
		{
			for (std::size_t i = 0; i < first.string_length; i++)
			{
				if (first.raw_string[i] != other_c_string[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool operator!=(const String& first, const char* other_c_string) noexcept
	{
		return !(first == other_c_string);
	}

	bool operator==(const String& first, const String& second) noexcept
	{
		return first == second.raw_string;
	}

	bool operator!=(const String& first, const String& second) noexcept
	{
		return !(first == second);
	}

	String operator+(const String& first, const char* c_string)
	{
		String result;
		std::size_t c_string_length = std::strlen(c_string);
		std::size_t sum_length = first.string_length + c_string_length;
		result.reserve(sum_length + 1);
		Algorithms::Copying::copy_data_into_array(result.raw_string, first.string_length, first.raw_string);
		Algorithms::Copying::copy_data_into_array(result.raw_string + first.string_length,
				c_string_length, c_string);
		result.string_length = sum_length;
		return result;
	}

	String& String::operator+=(const char* c_string)
	{
		std::size_t c_string_length = std::strlen(c_string);
		std::size_t new_length = string_length + c_string_length;
		char* temp{};
		if (c_string == this->raw_string)
		{
			temp = new char[c_string_length + 1](); // for possible self operation: str+=str;
			Algorithms::Copying::copy_data_into_array(temp, c_string_length, c_string);
		}

		if (new_length + 1 > capacity)
		{
			reserve(static_cast<std::size_t>(1.5 * static_cast<double>(new_length)) + 1);
		}
		Algorithms::Copying::copy_data_into_array(raw_string + string_length, c_string_length,
				temp == nullptr ? c_string : temp);
		string_length = new_length;
		delete[] temp;
		return *this;
	}

	String operator+(const String& first, const String& second)
	{
		return first + second.raw_string;
	}

	String& String::operator+=(const String& other)
	{
		*this += other.raw_string;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const String& basicString)
	{
		if (basicString.raw_string != nullptr)
		{
			stream << basicString.raw_string;
		}
		return stream;
	}

	void String::swap(String& first, String& second) noexcept
	{
		std::swap(first.raw_string, second.raw_string);
		std::swap(first.string_length, second.string_length);
		std::swap(first.capacity, second.capacity);
	}

}

