#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConvert
{
  public:
    ScalarConvert();
    ScalarConvert(ScalarConvert& scalarConvert);
    ScalarConvert& operator=(const ScalarConvert& scalarConvert);
    virtual ~ScalarConvert() = 0;
    static void convert(const std::string& litt);
};

#endif
