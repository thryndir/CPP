#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  private:
    std::string ideas[100];
  public:
    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();
};

#endif
