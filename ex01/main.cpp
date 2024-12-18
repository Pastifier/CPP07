#include "iter.hpp"
#include <cstddef>
#include <iostream>
//
// void myToUpper(char *p) {
//   if (*p >= 'a' && *p <= 'z')
//     *p -= 32;
// }
//
// void myBZero(int *p) { *p = 0; }
//
// int main(void) {
//   char carr[13] = "Hello, world";
//   int *iarr = new int[13];
//
//   iter<char>(carr, 13, myToUpper);
//   iter<int>(iarr, 13, myBZero);
//
//   std::cout << carr << "\n";
//   for (int i = 0; i < 13; i++)
//     std::cout << iarr[i];
//   std::cout << std::endl;
//   return 0;
// }

//// Eval main.
class Awesome {
public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

private:
  int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}

template <typename T> void print(T &x) {
  std::cout << x << std::endl;
  return;
}

void myMemcpy(const void *src, void *dst, std::size_t nbytes) {
  char *csrc = static_cast<char *>(const_cast<void *>(src));
  char *cdst = static_cast<char *>(dst);

  for (std::size_t i = 0; i < nbytes; i++)
    cdst[i] = csrc[i];
}

int main() {
  int tab[] = {0, 1, 2, 3, 4};
  Awesome tab2[5];

  char *tab3 = new char[13];
  myMemcpy("Hello, world!", tab3, 13);
  iter(tab, 5, print<const int>);
  iter(tab2, 5, print<Awesome>);

  std::cout << tab3 << std::endl;

  return 0;
}