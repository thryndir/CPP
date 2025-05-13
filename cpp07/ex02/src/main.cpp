#include <exception>
#include <iostream>
#include "Array.hpp"

int main( void )
{
  Array<int> intArray1;
  Array<char> NullArray;
  Array<int> intArray2(8);
  Array<char> charArray(10);
  Array<int> tinyArray(1);
  try
  {
    for (unsigned int i = 0; i < intArray2.size(); i++)
    {
      intArray2[i] = 8;
    }
    intArray2.print("intArray2");
    intArray1 = intArray2;
    intArray1.print("intArray1");
    for (unsigned int i = 0; i < charArray.size(); i++)
      charArray[i] = 'a';
    charArray.print("charArray");
    tinyArray = intArray1;
    tinyArray.print("tinyArray");
    Array<int> copyArray(intArray2);
    copyArray.print("copyArray");
    intArray2 = intArray1;
    intArray2.print("intArray2");
  }
   catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  try
  {
    NullArray[3];
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
  }
  return 0;
}
