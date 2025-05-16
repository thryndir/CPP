#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
class Span
{
  private:
    unsigned int _N;
    std::vector<int> _array;
  public:
    Span(int span = 0);
    Span(const Span& span);
    Span& operator=(const Span& span);
    ~Span();
    void addNumber(int number);
    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);
    void addSequence(std::vector<int>::iterator start, std::vector<int>::iterator end);
    std::vector<int>& getArray(void);
};

#endif
