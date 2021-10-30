#ifndef SOURCE_BASICSTRING_HPP
#define SOURCE_BASICSTRING_HPP

#include <cstddef>
#include <ostream>
#include "StringIterator.hpp"

/// \brief Contains data structures.
namespace DataStructures
{

	/// \brief String class.
	struct String
	{

		/// \brief Copy constructor.
		String(const String& string);

		/// \brief Move constructor.
		String(String&& string) noexcept;

		/// \brief Copy assignment operator.
		String& operator=(const String& other);

		/// \brief Move assignment operator.
		String& operator=(String&& other) noexcept;

		/// \brief Virtual destructor.
		virtual ~String() noexcept;

		/// \brief Default constructs. Initializes empty string.
		String();

		/// \brief Constructor from C string.
		/// \param string String for constructing from.
		explicit String(const char* string);

		/// \brief Resets the string completely.
		/// \remark After this sting will be really empty with capacity of 1 and length 0.
		void reset();

		/// \brief Clears the string. Capacity remains unchanged, but length will be 0.
		void clear();

		/// \brief Reserves memory (dynamic) for n string symbols.
		/// \param n Number of string symbols to reserve memory for.
		/// \remark If n &le capacity then nothing happens.
		/// Otherwise new memory is allocated and raw_string is being copied to new location.
		void reserve(std::size_t n);

		/// Reduces capacity to string length + 1.
		void shrink_to_fit();

		/// \brief Returns C string, represented by current string object.
		[[nodiscard]] const char* get_c_str() const;

		/// \brief Returns capacity.
		[[nodiscard]] size_t get_capacity() const;

		/// \brief Returns length.
		[[nodiscard]] size_t get_length() const;

		/// \brief Returns first symbol of string.
		[[nodiscard]] char get_first() const;

		/// \brief Returns last symbol of string.
		[[nodiscard]] char get_last() const;

		/// \brief Returns an iterator to the beginning of the string.
		/// \return Iterator pointing to the first symbol of the string.
		[[nodiscard]] StringIterator begin() const;

		/// \brief Returns an iterator to the end of the string.
		/// \return Iterator pointing to '\0' symbol after the end of the string.
		[[nodiscard]] StringIterator end() const;

		/// \brief Reverses current string.
		void reverse();

		/// \brief Returns a new string, that is reversed current string.
		[[nodiscard]] String get_reversed() const;

		/// \brief Returns a symbol at position = index.
		/// \remark Does not check that index is less than current string length.
		[[nodiscard]] char operator[](std::size_t index) const;

		/// \brief Returns a reference to a symbol at position = index.
		/// \remark Does not check that index is less than current string length.
		[[nodiscard]] char& operator[](std::size_t index);

		/// \brief Returns a reference to a symbol at position = index.
		/// \remark Checks that index is less than current string length.
		/// \throws std::out_of_range exception if index &ge current string length.
		[[nodiscard]] char& at(std::size_t index);

		/// \brief Returns a symbol at position = index.
		/// \remark Checks that index is less than current string length.
		/// \throws std::out_of_range exception if index &ge current string length.
		[[nodiscard]] char at(std::size_t index) const;

		/// \brief Return a new string that is a slice of current string from first_index to last_index inclusive.
		[[nodiscard]] String get_slice(std::size_t first_index, std::size_t last_index) const;

		/// \brief Checks whether current string (represented as C string) is equal to another_c_string.
		friend bool operator==(const String& first, const char* another_c_string) noexcept;

		/// \brief Checks whether current string (represented as C string) is not equal to another_c_string.
		friend bool operator!=(const String& first, const char* another_c_string) noexcept;

		/// \brief Checks whether current string is equal to another string.
		friend bool operator==(const String& first, const String& second) noexcept;

		/// \brief Checks whether current string is not equal to another string.
		friend bool operator!=(const String& first, const String& second) noexcept;

		/// \brief Returns a new string that is a concatenation of current string and another C string.
		friend String operator+(const String& first, const char* c_string);

		/// \brief Concatenates current string and c_string (represented as C string).
		String& operator+=(const char* c_string);

		/// \brief Returns a new string that is a concatenation of current string and another string.
		friend String operator+(const String& first, const String& second);

		/// \brief Concatenates current string and c_string (represented as C string).
		String& operator+=(const String& other);

		/// \brief Outputs current string to stream.
		friend std::ostream& operator<<(std::ostream& stream, const String& basicString);

	 private:
		/// \brief C string for representing String content.
		char* raw_string{ nullptr };

		/// \brief Length of current string. '\0' at the end is not counted.
		std::size_t string_length{};

		/// \brief Number of allocated chars to store C string.
		std::size_t capacity{};

		/// \brief Swaps first string with second one.
		static void swap(String& first, String& second) noexcept;
	};

}

#endif //SOURCE_BASICSTRING_HPP
