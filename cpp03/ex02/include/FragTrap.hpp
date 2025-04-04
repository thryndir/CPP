#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    explicit FragTrap(const std::string& name = "", int hPoints = 100,
       int ePoints = 100, int aDamage = 30);
    FragTrap(const FragTrap& scavTrap);
    FragTrap&  operator=(const FragTrap& scavtrap);
    ~FragTrap();
    void  highFivesGuys(void);
};

#endif
