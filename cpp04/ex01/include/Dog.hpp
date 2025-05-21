#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
  public:
    Dog(std::string type = "Dog");
    Dog(const Dog& dog);
    virtual ~Dog();
    Dog& operator=(const Dog& dog);
    virtual void makeSound() const;
    Brain& getBrain(void);
  private:
    Brain* _brain;
};

#endif
