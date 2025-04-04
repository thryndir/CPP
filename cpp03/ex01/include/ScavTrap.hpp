#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp" 

class ScavTrap : public ClapTrap
{
  public:
    explicit ScavTrap(const std::string& name = "", int hPoints = 100,
       int ePoints = 50, int aDamage = 20);
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap&  operator=(const ScavTrap& scavtrap);
    ~ScavTrap();
    void  guardGate();
    void  attack(const std::string& target);
};

#endif
