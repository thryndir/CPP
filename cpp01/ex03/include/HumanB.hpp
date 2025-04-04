#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
  private:
    std::string mName;
    Weapon* mWeapon;
  public:
    HumanB(const std::string& name);
    void  setWeapon(Weapon& Weapon);
    void  attack(void);
};

#endif
