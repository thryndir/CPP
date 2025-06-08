#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
  private:
    std::string _input;
    std::stack<double> _stack;
  public:
    RPN(const std::string& str);
    RPN(const RPN& rpn);
    RPN& operator=(const RPN& rpn);
    ~RPN();
    double compute(void);
    void debugPrintStack() const;
};

#endif
