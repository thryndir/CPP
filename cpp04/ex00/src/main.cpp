#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();
  const WrongAnimal* test = new WrongAnimal();
  const WrongAnimal* test1 = new WrongCat();
  std::cout << test->getType() << " " << std::endl;
  std::cout << test1->getType() << " " << std::endl;
  test->makeSound();
  test1->makeSound();
  delete meta;
  delete j;
  delete i;
  delete test;
  delete test1;
  return 0;
}
