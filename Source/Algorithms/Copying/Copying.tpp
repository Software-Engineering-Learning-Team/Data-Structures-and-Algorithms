#ifndef SOURCE_ALGORITHMS_COPYING_TPP
#define SOURCE_ALGORITHMS_COPYING_TPP

/// Contains algorithms.
namespace Algorithms
{
	/// For performing copying.
	namespace Copying
	{
		/// Fills array of size n with values.
		/// \tparam T Underlying array type.
		/// \param array Array to fill.
		/// \param n Number values to fill the array.
		/// \param value Value to fill the array.
		template<typename T>
		static void fill_array(T array[], std::size_t n, const T value)
		{
			for (std::size_t i = 0; i < n; i++)
			{
				array[i] = value;
			}
		}

		/// Copies content from source array to destination one. Element by element.
		/// \tparam T Underlying array type.
		/// \param destination Array to copy to.
		/// \param n Number of positions to copy.
		/// \param source Array to copy from.
		template<typename T>
		static void copy_data_into_array(T destination[], std::size_t n, const T source[])
		{
			for (std::size_t i = 0; i < n; i++)
			{
				destination[i] = source[i];
			}
		}
	};

}
#endif //SOURCE_ALGORITHMS_COPYING_TPP
