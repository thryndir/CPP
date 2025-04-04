#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name, int hPoints, int ePoints, int aDamage)
  :ClapTrap(name, hPoints, ePoints, aDamage)
{
  std::cout << "(FragTrap) constructor called\n";
}

FragTrap::FragTrap(const FragTrap& fragTrap)
  :ClapTrap(fragTrap.getName(), fragTrap.getHpoints(), fragTrap.getEpoints()
    , fragTrap.getAdamage())
{
  std::cout << "(FragTrap) copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
  if (this == &fragTrap)
    return (*this);
  setName(fragTrap.getName());
  setHpoints(fragTrap.getHpoints());
  setEpoints(fragTrap.getEpoints());
  setAdamage(fragTrap.getAdamage());
  std::cout << "(FragTrap) copy assignement operator called\n";
  return (*this);
}

FragTrap::~FragTrap()
{
  std::cout << "(FragTrap) destructor called\n";
}

void  FragTrap::highFivesGuys()
{
  std::cout << "(FragTrap) " << getName() << " Check it up ma boyyyys !\n";
}
