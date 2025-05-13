#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name, int hPoints, int ePoints, int aDamage)
  :mName(name)
  ,mHitPoints(hPoints)
  ,mEnergyPoints(ePoints)
  ,mAttackDamage(aDamage)
{
  std::cout << "(ClapTrap) constructor called\n";
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
  std::cout << "(ClapTrap) copy assignement operator called\n";
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
  std::cout << "(ClapTrap) destructor called\n";
}

void  ClapTrap::attack(const std::string& target)
{
  if (mEnergyPoints && mHitPoints)
  {
    std::cout << "(ClapTrap) " << mName << " attacks " <<
      target << " causing " << mAttackDamage << " points of damage !" << '\n';
    setEpoints(getEpoints()-1);
  }
  else
    std::cout << mName << " can't attack" << std::endl;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
  if (mEnergyPoints && mHitPoints)
  {
    setHpoints(getHpoints() - amount);
    std::cout << mName << " has taken " <<
      amount << " points of damage!" << '\n';
  }
  else
    std::cout << mName << " can't take damage" << std::endl;
}

void  ClapTrap::beRepaired(unsigned int amount)
{
  if (mEnergyPoints && mHitPoints)
  {
    std::cout << mName << " is being repaired by " <<
      amount << " points !" << '\n';
    setEpoints(getEpoints()-1);
    setHpoints(getHpoints() + amount);
  }
  else
    std::cout << mName << " can't be repaired" << std::endl;
}

const  std::string& ClapTrap::getName(void) const
{
  return (mName);
}

int  ClapTrap::getHpoints(void) const
{
  return (mHitPoints);
}

int  ClapTrap::getEpoints(void) const
{
  return (mEnergyPoints);
}

int  ClapTrap::getAdamage(void) const
{
  return (mAttackDamage);
}

void  ClapTrap::setName(const std::string& name)
{
  mName = name;
}

void  ClapTrap::setHpoints(const int hPoints)
{
  mHitPoints = hPoints;
}

void  ClapTrap::setEpoints(const int ePoints)
{
  mEnergyPoints = ePoints;
}

void  ClapTrap::setAdamage(const int aDamage)
{
  mAttackDamage = aDamage;
}
