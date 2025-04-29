#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
  private:
    std::string mType;
  public:
    Weapon(std::string weaponType = "");
    const std::string&  getType() const;
    void  setType(const std::string& str);
};

#endif
