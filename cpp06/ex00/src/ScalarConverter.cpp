#include "ScalarConverter.hpp"
#include <algorithm>
#include <sstream>
#include <string>

static bool isChar(const std::string& litt)
{
  return (std::isprint(litt[0]) && litt.length() == 1 && std::isdigit(litt[0]));
}

static bool isInt(const std::string& litt)
{
  size_t i(0);
  if (!litt.empty() && (*litt.begin() == '+' || *litt.begin() == '-'))
    i = 1;
  if (litt.find_first_not_of("0123456789", i) != litt.npos)
    return (false);
  return (true);
}

static bool isFloat(const std::string& litt)
{
  size_t i(0);
  if (!litt.empty() && (*litt.begin() == '+' || *litt.begin() == '-'))
    i = 1;
  size_t suffix = litt.find('f');
  size_t dot = litt.find('.');
  if (std::count(litt.begin(), litt.end(), '.') >= 2
       || std::count(litt.begin(), litt.end(), 'f') >= 2 )
    return (false);
  if (suffix != litt.length() - 1 || dot == 0 || dot != litt.length() - 1)
    return (false);
  if (litt.find_first_not_of("0123456789.f", i) != litt.npos)
    return (false);
  return (true);
}

static bool isDouble(const std::string& litt)
{
  size_t i(0);
  if (!litt.empty() && (*litt.begin() == '+' || *litt.begin() == '-'))
    i = 1;
  size_t dot = litt.find('.');
  if (std::count(litt.begin(), litt.end(), '.') > 1)
    return (false);
  if (dot == 0 || dot != litt.length() - 1)
    return (false);
  if (litt.find_first_not_of("0123456789.", i) != litt.npos)
    return (false);
  return (true);
}

static bool isInfinite(const std::string& litt)
{
  return (litt == "+inff" || litt == "-inff" || litt == "+inf"
          || litt == "-inf" || litt == "nanf" || litt == "nan");
}

void ScalarConvert::convert(std::string litt) const
{
  std::stringstream intLitt;
  std::stringstream charLitt;
  std::stringstream floatLitt;
  std::stringstream doubleLitt;

  if (isChar(litt))
    charLitt << litt;
  else if (isInt(litt))
    intLitt << litt;
  else if (isFloat(litt))
    floatLitt << litt;
  else if (isDouble(litt))
    doubleLitt << litt;
  else if (isInfinite(litt))
    ;
}
