#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
  :mName(name)
  ,mHitPoints(10)
  ,mEnergyPoints(10)
  ,mAttackDamage(0)
{
  std::cout << "(ClapTrap) construcor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
  :mName(clapTrap.mName)
  ,mHitPoints(clapTrap.mHitPoints)
  ,mEnergyPoints(clapTrap.mEnergyPoints)
  ,mAttackDamage(clapTrap.mAttackDamage)
{
  std::cout << "(ClapTrap) copy constructor called\n";
}

ClapTrap&  ClapTrap::operator=(const ClapTrap& clapTrap)
{
  std::cout << "(ClapTrap) copy assignement operator called \n";
  if (this == &clapTrap)
    return (*this);
  mName = clapTrap.mName;
  mHitPoints = clapTrap.mHitPoints;
  mEnergyPoints = clapTrap.mEnergyPoints;
  mAttackDamage = clapTrap.mAttackDamage;
  return (*this);
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap destroyed\n";
}

void  ClapTrap::attack(const std::string& target)
{
  if (mEnergyPoints && mHitPoints)
    std::cout << "ClapTrap " << mName << " attacks " <<
      target << " causing " << mAttackDamage << " points of damage !" << '\n';
}

void  ClapTrap::takeDamage(unsigned int amount)
{
  std::cout << "ClapTrap " << mName << " has taken " <<
    amount << " points of damage!" << '\n';
}

void  ClapTrap::beRepaired(unsigned int amount)
{
  if (mEnergyPoints && mHitPoints)
    std::cout << "ClapTrap " << mName << " is being repaired by " <<
      amount << " points !" << '\n';
}
