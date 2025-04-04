#include "ClapTrap.hpp"
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap MachineA("Roboto");
  ClapTrap MachineB("Roboto");
  std::cout << "I am " << MachineA.getName() << std::endl
            << "HitPoints: " << MachineA.getHpoints() << std::endl
            << "EnergyPoints: " << MachineA.getEpoints() << std::endl
            << "AttackDamage: " << MachineA.getAdamage() << std::endl;
  MachineA.attack(MachineB.getName());
  MachineB.takeDamage(5);
  MachineA.beRepaired(1);

  std::cout << std::endl << std::endl;

  ScavTrap ScavA("Robert");
  std::cout << "I am " << ScavA.getName() << std::endl
            << "HitPoints: " << ScavA.getHpoints() << std::endl
            << "EnergyPoints: " << ScavA.getEpoints() << std::endl
            << "AttackDamage: " << ScavA.getAdamage() << std::endl;
  ScavA.guardGate();
  ScavA.attack("Pigeon");
  ScavA.takeDamage(10);

  ScavTrap ScavB(ScavA);
  ScavB.beRepaired(5);
  ScavB.beRepaired(1);

  ScavTrap ScavC = ScavA;
  ScavC.takeDamage(100);
  ScavC.takeDamage(100);
  ScavC.attack("Perry");

  FragTrap FragA("Michele");
  std::cout << "I am " << FragA.getName() << std::endl
            << "HitPoints: " << FragA.getHpoints() << std::endl
            << "EnergyPoints: " << FragA.getEpoints() << std::endl
            << "AttackDamage: " << FragA.getAdamage() << std::endl;
  for (int i = 0; i <= 100; i++) {
    std::cout << FragA.getEpoints() << " ";
    FragA.attack("Tester");
  }

  FragTrap FragB(FragA);
  std::cout << FragB.getEpoints() << " ";
  FragB.attack("Tester");

  FragTrap FragC("Replaced");
  FragC = FragB;
  std::cout << FragC.getEpoints() << " ";
  FragC.attack("Tester");

  return 0;
}
