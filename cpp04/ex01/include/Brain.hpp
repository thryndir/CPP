#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
  private:
    std::string _ideas[100];
  public:
    Brain();
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
    ~Brain();
    void display(const std::string& name);
    void setIdeas(const std::string& std);
};

#endif
