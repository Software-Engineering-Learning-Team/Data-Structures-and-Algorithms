#ifndef SOURCE_DATASTRUCTURES_STRING_STRINGITERATOR_HPP
#define SOURCE_DATASTRUCTURES_STRING_STRINGITERATOR_HPP

namespace DataStructures
{
	/// Iterator for DataStructures::String objects.
	struct StringIterator
	{
		/// Iterator constructor.
		/// \param ptr C string for iterating through.
		explicit StringIterator(char* ptr) : pointer(ptr)
		{
		}

		/// Moves iterator right.
		StringIterator& operator++()
		{
			++pointer;
			return *this;
		}

		/// Checks whether current iterator is not equal to another one.
		bool operator!=(const StringIterator& another) const
		{
			return pointer != another.pointer;
		}

		/// Returns a char at a current position.
		char operator*() const
		{
			return *pointer;
		}

		/// Returns a reference to char at a current position.
		char& operator*()
		{
			return *pointer;
		}

	private:
		/// C string for iterating through.
		char* pointer;
	};
}

#endif //SOURCE_DATASTRUCTURES_STRING_STRINGITERATOR_HPP
