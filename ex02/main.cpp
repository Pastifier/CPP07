#include "Array.hpp"
#include <exception>
#include <iostream>

#define PRINT(X) std::cout << X
#define FLUSH() std::cout << std::endl;

class ComplexClass {
public:
  ComplexClass() { _val = 0; }
  ComplexClass(ComplexClass const &other) : _val(other.getVal()) {}
  int getVal() const { return _val; };
  void setVal(int val_) { _val = val_; }

private:
  int _val;
};

int main(void) {
  PRINT("========== TESTING DEFAULT CONSTRUCTOR ==========\n");
  Array<int> itab;
  PRINT("itab val: " << itab[0] << "\n");

  Array<ComplexClass> comTab;
  PRINT("comTab val: " << comTab[0].getVal() << "\n");

  PRINT("========== TESTING   COPY  CONSTRUCTOR ==========\n");
  Array<char> ctab(14);
  for (unsigned int i = 0; i < ctab.size() - 1; i++)
    ctab[i] = 's';
  PRINT("ctab: \"" << ctab.getAddr() << "\"\n");
  Array<char> ctab2(ctab);
  PRINT("ctab2: \"" << ctab2.getAddr() << "\"\n");

  Array<ComplexClass> comTab2(12);
  for (int i = 0; i < 12; i++) {
    comTab2[i].setVal(i);
  }
  PRINT("comTab2: ");
  for (int i = 0; i < 12; i++) {
    PRINT(comTab2[i].getVal() << (i == 11 ? ";;\n" : ","));
  }

  Array<ComplexClass> comTab3(comTab2);
  PRINT("comTab3: ");
  for (int i = 0; i < 12; i++) {
    PRINT(comTab3[i].getVal() << (i == 11 ? ";;\n" : ","));
  }

  Array<int> itab2(12);
  for (int i = 0; i < 12; i++) {
    itab2[i] = i * 2;
  }
  PRINT("itab2: ");
  for (int i = 0; i < 12; i++) {
    PRINT(itab2[i] << (i == 11 ? ";;\n" : ","));
  }

  PRINT("========== TESTING SUBSCRIPT EXCEPTION ==========\n");
  try {
    PRINT("itab2 size: " << itab2.size() << "\n");
    itab2[itab2.size()] = 0;
  } catch (std::exception &e) {
    std::cerr << e.what() << "\n";
  }

  FLUSH();
  return 0;
}
