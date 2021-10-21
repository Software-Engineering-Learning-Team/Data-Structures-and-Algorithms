#ifndef SOURCE_BASICSTRING_HPP
#define SOURCE_BASICSTRING_HPP

#include <cstddef>
#include <ostream>
#include "StringIterator.hpp"

/// Contains data structures.
namespace DataStructures
{

/// String class.
/// \example String/BasicStringExamples.hpp
	struct String
	{

		/// Copy constructor.
		String(const String& string);

		/// Move constructor.
		String(String&& string) noexcept;

		/// Copy assignment operator.
		String& operator=(const String& other);

		/// Move assignment operator.
		String& operator=(String&& other) noexcept;

		/// Virtual destructor.
		virtual ~String() noexcept;

		/// Default constructs. Initializes empty string.
		String();

		/// Constructor from C string.
		/// \param string String for constructing from.
		explicit String(const char* string);

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

		/// Returns C string, represented by current string object.
		[[nodiscard]] const char* get_c_str() const;

		/// Returns capacity.
		[[nodiscard]] size_t get_capacity() const;

		/// Returns length.
		[[nodiscard]] size_t get_length() const;

		/// Returns first symbol of string.
		[[nodiscard]] char get_first() const;

		/// Returns last symbol of string.
		[[nodiscard]] char get_last() const;

		/// Returns an iterator to the beginning of the string.
		/// \return Iterator pointing to the first symbol of the string.
		[[nodiscard]] StringIterator begin() const;

		/// Returns an iterator to the end of the string.
		/// \return Iterator pointing to '\0' symbol after the end of the string.
		[[nodiscard]] StringIterator end() const;

		/// Reverses current string.
		void reverse();

		/// Returns a new string, that is reversed current string.
		[[nodiscard]] String get_reversed() const;

		/// Returns a symbol at position = index.
		/// \remark Does not check that index is less than current string length.
		[[nodiscard]] char operator[](std::size_t index) const;

		/// Returns a reference to a symbol at position = index.
		/// \remark Does not check that index is less than current string length.
		[[nodiscard]] char& operator[](std::size_t index);

		/// Returns a reference to a symbol at position = index.
		/// \remark Checks that index is less than current string length.
		/// \throws std::out_of_range exception if index &ge current string length.
		[[nodiscard]] char& at(std::size_t index);

		/// Returns a symbol at position = index.
		/// \remark Checks that index is less than current string length.
		/// \throws std::out_of_range exception if index &ge current string length.
		[[nodiscard]] char at(std::size_t index) const;

		/// Return a new string that is a slice of current string from first_index to last_index inclusive.
		[[nodiscard]] String get_slice(std::size_t first_index, std::size_t last_index) const;

		/// Checks whether current string (represented as C string) is equal to another_c_string.
		friend bool operator==(const String& first, const char* another_c_string) noexcept;

		/// Checks whether current string (represented as C string) is not equal to another_c_string.
		friend bool operator!=(const String& first, const char* another_c_string) noexcept;

		/// Checks whether current string is equal to another string.
		friend bool operator==(const String& first, const String& second) noexcept;

		/// Checks whether current string is not equal to another string.
		friend bool operator!=(const String& first, const String& second) noexcept;

		/// Returns a new string that is a concatenation of current string and another C string.
		friend String operator+(const String& first, const char* c_string);

		/// Concatenates current string and c_string (represented as C string).
		String& operator+=(const char* c_string);

		/// Returns a new string that is a concatenation of current string and another string.
		friend String operator+(const String& first, const String& second);

		/// Concatenates current string and c_string (represented as C string).
		String& operator+=(const String& other);

		/// Outputs current string to stream.
		friend std::ostream& operator<<(std::ostream& stream, const String& basicString);

	private:
		/// C string for representing String content.
		char* raw_string{ nullptr };

		/// Length of current string. '\0' at the end is not counted.
		std::size_t string_length{};

		/// Number of allocated chars to store C string.
		std::size_t capacity{};

		/// Swaps first string with second one.
		static void swap(String& first, String& second) noexcept;
	};

}

#endif //SOURCE_BASICSTRING_HPP
