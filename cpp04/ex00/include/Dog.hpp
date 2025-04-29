#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
  public:
    Dog(std::string type = "Dog");
    Dog(const Dog& dog);
    ~Dog();
    virtual Dog& operator=(const Dog& dog);
    virtual void makeSound() const;
};

#endif
