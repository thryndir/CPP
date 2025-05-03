#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConvert
{
  public:
    void test(void);
    virtual void convert(std::string litt) const = 0;
};

#endif
