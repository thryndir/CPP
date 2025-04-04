#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name, int hPoints, int ePoints, int aDamage)
  :ClapTrap(name, hPoints, ePoints, aDamage)
{
  std::cout << "(ScavTrap) constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
  :ClapTrap(scavTrap.getName(), scavTrap.getHpoints(), scavTrap.getEpoints()
    , scavTrap.getAdamage())
{
  std::cout << "(ScavTrap) copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
  if (this == &scavTrap)
    return (*this);
  setName(scavTrap.getName());
  setHpoints(scavTrap.getHpoints());
  setEpoints(scavTrap.getEpoints());
  setAdamage(scavTrap.getAdamage());
  std::cout << "(ScavTrap) copy assignement operator called\n";
  return (*this);
}

ScavTrap::~ScavTrap()
{
  std::cout << "(ScavTrap) destructor called\n";
}

void  ScavTrap::guardGate()
{
  std::cout << "(ScavTrap) " << getName() << " is now in gatekeeper mode\n";
}
