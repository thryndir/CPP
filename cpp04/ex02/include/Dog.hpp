#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
  public:
    explicit Dog(std::string type = "Dog");
    Dog(const Dog& dog);
    ~Dog();
    virtual Dog& operator=(const Dog& dog);
    virtual void makeSound() const;
    private:
      Brain* brain;
};

#endif
