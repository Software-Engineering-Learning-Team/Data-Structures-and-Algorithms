#ifndef DATASTRUCTURESANDALGORITHMS_BASICSTRINGEXAMPLES_HPP
#define DATASTRUCTURESANDALGORITHMS_BASICSTRINGEXAMPLES_HPP

using DataStructures::String;

void ProcessBasicStringExamples()
{
	String string("Hello, World!");
	std::cout << "Length is \t" << string.get_length() << "\n";
	std::cout << "Capacity is \t" << string.get_capacity() << "\n";

}

#endif //DATASTRUCTURESANDALGORITHMS_BASICSTRINGEXAMPLES_HPP
