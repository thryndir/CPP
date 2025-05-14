#include <iostream>
#include "iter.hpp"

int main( void )
{
  std::string dyna("dynamicArray");
  std::string stat("staticArray");
  int *dynamicArray = new int[8];
  const int* constArray = new int[10];
  int staticArray[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  iter(dynamicArray, 8, initialise);
  iter(dynamicArray, 8, "dynamicArray");
  iter(staticArray, 8, "staticArray");
  iter(staticArray, 8, multiply);
  iter(staticArray, 8, "staticArray");
  iter(staticArray, 8, initialise);
  iter(staticArray, 8, "staticArray");
  iter(dynamicArray, 8, multiply);
  iter(dynamicArray, 8, "dynamicArray");
  iter(constArray, 10, "constArray");
  delete[] dynamicArray;
  return 0;
}
