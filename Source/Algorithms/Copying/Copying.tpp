#ifndef SOURCE_ALGORITHMS_COPYING_TPP_
#define SOURCE_ALGORITHMS_COPYING_TPP_
namespace Algorithms
{

	struct Copying
	{
		template<typename T>
		static void fill_array(T* array, std::size_t n, const T value)
		{
			for (std::size_t i = 0; i < n; i++)
			{
				array[i] = value;
			}
		}

		template<typename T>
		static void copy_data_into_array(T* destination, std::size_t n, const T* source)
		{
			for (std::size_t i = 0; i < n; i++)
			{
				destination[i] = source[i];
			}
		}
	};

}
#endif //SOURCE_ALGORITHMS_COPYING_TPP_
