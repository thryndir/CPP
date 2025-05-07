#include "ScalarConverter.hpp"
#include <cctype>
#include <limits>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

ScalarConvert::ScalarConvert()
{}

ScalarConvert::ScalarConvert(const ScalarConvert& scalarConvert)
{
  (void)scalarConvert;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& scalarConvert)
{
  if (&scalarConvert == this)
    return (*this);
  return (*this);
}

ScalarConvert::~ScalarConvert()
{}

static int countOccur(const std::string& str, char toCount)
{
  int count(0);

  for (size_t i = 0; i <= str.length(); i++)
  {
    if (str[i] == toCount)
      count++;
  }
  return (count);
}

static bool isChar(const std::string& litt)
{
  return (std::isprint(litt[0]) && litt.length() == 1 && !std::isdigit(litt[0]));
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
  size_t dot = litt.find('.');
  size_t suffix = litt.find('f');
  if (countOccur(litt, '.') > 1 || countOccur(litt, 'f') > 1 )
    return (false);
  if (suffix != litt.length() - 1 || dot == 0 || dot == litt.length() - 2)
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
  if (countOccur(litt, '.') > 1)
    return (false);
  if (*litt.begin() == '.' || *litt.end() == '.')
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

static void convertFromChar(std::stringstream& origin)
{
  char toDisplay;
  if (!(origin >> toDisplay))
    std::cout << "char: impossible\n";
  else if (!std::isprint(toDisplay))
    std::cout << "char: Non displayable\n";
  else
    std::cout << "char: " << "'" << toDisplay << "'" << "\n";
  if (std::floor(toDisplay) == toDisplay)
      std::cout << std::fixed << std::setprecision(1);
  std::cout << "int: " << static_cast<int>(toDisplay) << "\n";
  std::cout << "float: " << static_cast<float>(toDisplay) << "f\n";
  std::cout << "double: " << static_cast<double>(toDisplay) << "\n";
  std::cout.unsetf(std::ios::fixed);
}

static void convertFromNbr(std::stringstream& origin)
{
  long double toDisplay;
  origin >> toDisplay;

  if (std::floor(toDisplay) == toDisplay)
      std::cout << std::fixed << std::setprecision(1);
  if (toDisplay < std::numeric_limits<char>::min()
    || toDisplay > std::numeric_limits<char>::max())
    std::cout << "char: " << "impossible\n";
  else if (!std::isprint(toDisplay))
    std::cout << "char: Non displayable\n";
  else
    std::cout << "char: " << "'" << static_cast<char>(toDisplay) << "'" << "\n";

  if (toDisplay < std::numeric_limits<int>::min()
    || toDisplay > std::numeric_limits<int>::max())
    std::cout << "int: " << "impossible\n";
  else
    std::cout << "int: " << static_cast<int>(toDisplay) << "\n";

  if (toDisplay < -std::numeric_limits<float>::max()
    || toDisplay > std::numeric_limits<float>::max())
    std::cout << "float: " << "impossible\n";
  else
    std::cout << "float: " << static_cast<float>(toDisplay) << "f\n";

  if (toDisplay < -std::numeric_limits<double>::max()
    || toDisplay > std::numeric_limits<double>::max())
    std::cout << "double: " << "impossible\n";
  else
    std::cout << "double: " << static_cast<double>(toDisplay) << "\n";
  std::cout.unsetf(std::ios::fixed);
}

static void convertFromInfinite(const std::string& litt)
{
  std::cout << "char: " << "impossible\n";
  std::cout << "int: " << "impossible\n";
  if (litt == "-inf" || litt == "+inf" || litt == "nan")
    std::cout << "float: " << "impossible\n";
  else
    std::cout << "float: " << litt << "\n";
  if (litt == "-inff" || litt == "+inff" || litt == "nanf")
    std::cout << "double: " << "impossible\n";
  else
    std::cout << "double: " << litt << "\n";
}

void ScalarConvert::convert(const std::string& litt)
{
  std::stringstream origin(litt);
  if (isChar(litt))
    convertFromChar(origin);
  else if (isInt(litt))
    convertFromNbr(origin);
  else if (isFloat(litt))
    convertFromNbr(origin);
  else if (isDouble(litt))
    convertFromNbr(origin);
  else if (isInfinite(litt))
    convertFromInfinite(litt);
  else
    std::cout << "base type not found\n";
}
