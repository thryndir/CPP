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
    static Fixed&  min(Fixed& fixed0, Fixed& fixed1);
    static const Fixed&  min(const Fixed& fixed0, const Fixed& fixed1);
    static Fixed&  max(Fixed& fixed0, Fixed& fixed1);
    static const Fixed&  max(const Fixed& fixed0, const Fixed& fixed1);
    bool  operator>(const Fixed& fixed) const;
    bool  operator<(const Fixed& fixed) const;
    bool  operator>=(const Fixed& fixed) const;
    bool  operator<=(const Fixed& fixed) const;
    bool  operator==(const Fixed& fixed) const;
    bool  operator!=(const Fixed& fixed) const;
    Fixed  operator+(const Fixed& fixed);
    Fixed  operator-(const Fixed& fixed);
    Fixed  operator*(const Fixed& fixed);
    Fixed  operator/(const Fixed& fixed);
    Fixed&  operator++();
    Fixed  operator++(int);
    Fixed&  operator--();
    Fixed  operator--(int);

};

  std::ostream&  operator<<(std::ostream& out, const Fixed& fixed);

#endif
