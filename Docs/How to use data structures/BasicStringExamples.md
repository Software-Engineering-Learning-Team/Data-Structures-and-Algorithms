# Examples for data structures
Here there are some simple examples of using data structures that will help you to figure out how to use them.
## String
### Basic usage
Let's first create a ```String``` and look at some of its properties. For example, it will represents ```Hello, World!``` string.
```cpp
String string("Hello, World!");
std::cout << "Length is \t" << string.get_length() << "\n";
std::cout << "Capacity is \t" << string.get_capacity() << "\n";
```
After that we will get
```console
Length is       13
Capacity is     14
```
The string takes up more memory than its length due to a null terminator at the end.