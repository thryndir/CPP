#include <stdint.h>
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
  Data test("test");
  std::cout << &test << std::endl;
  std::cout << Serializer::deserialize(Serializer::serialize(&test)) << std::endl;
  Data test2("test");
  std::cout << &test2 << std::endl;
  uintptr_t result2 = Serializer::serialize(&test2);
  std::cout << result2 << std::endl;
  std::cout << Serializer::deserialize(result2) << std::endl;
  return (0);
}
