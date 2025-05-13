#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
  ClapTrap test("test");
  test.attack("test");
  test.takeDamage(10);
  std::cout << test.getHpoints() << std::endl;
  test.beRepaired(8);
  std::cout << test.getHpoints() << std::endl;

  return 0;
}
