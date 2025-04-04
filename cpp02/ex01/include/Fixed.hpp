#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
  private:
    int         mFix;
    const static int  mFrac;
  public:
    Fixed();
    Fixed(const int fixed);
    Fixed(const float fixed);
    Fixed(const Fixed& fixed);
    float  toFloat(void) const;
    int    toInt(void) const;
    Fixed&  operator=(const Fixed& fixed);
    ~Fixed();
    int  getRawBits(void) const;
    void  setRawBits(const int raw);
};

  std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);

#endif
