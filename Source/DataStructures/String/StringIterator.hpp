#ifndef SOURCE_DATASTRUCTURES_STRING_STRINGITERATOR_HPP
#define SOURCE_DATASTRUCTURES_STRING_STRINGITERATOR_HPP

namespace DataStructures {
struct StringIterator {
  explicit StringIterator(char *ptr) : pointer(ptr) {}
  StringIterator &operator++() {
    ++pointer;
    return *this;
  }
  bool operator!=(const StringIterator &other) const { return pointer != other.pointer; }
  char operator*() const { return *pointer; }
 private:
  char *pointer;
};
}

#endif //SOURCE_DATASTRUCTURES_STRING_STRINGITERATOR_HPP
