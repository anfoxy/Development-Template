
#include "ClassMoney.h"

ostream& operator<<(ostream& stream, const Money& c);
istream& operator>>(istream& stream, Money& c);

Money::Money() {
  rub = 0.0;
  kop = 0.0;
}
Money::~Money() {
  rub = 0.0;
  kop = 0.0;
}
Money::Money(int _rub, int _kop) : rub(_rub), kop(_kop) {}

Money::Money(int d) {
  rub = d;
  kop = 0.0;
}

Money& Money::operator=(const Money& c) {
  (*this).rub = c.rub;
  kop = c.kop;
  return *this;
}
Money Money::operator-(const Money& c) {
  Money res;
  res.kop = (kop + rub * 100) - (c.kop + c.rub * 100);
  res.rub = res.kop / 100;
  res.kop = fmod(res.kop, 100);
  if (res.kop <= 0) res.kop = res.kop* -1;
  return res;
}
Money Money::operator*(double c) {
  Money res;
  res.kop = (kop + rub * 100)*c;
  res.rub = res.kop / 100;
  res.kop = fmod(res.kop, 100);
  return res;
}
Money Money::operator/(double c) {
  Money res;
  if (c == 0) throw std::logic_error("Error: div by zero!\n");
    res.kop = (kop + rub * 100) / c;
    res.rub = res.kop / 100;
    res.kop = fmod(res.kop, 100);
    return res;
  
}
Money Money::operator+(const Money& c) {
  Money res;
  res.rub = c.rub + rub;
  res.kop = c.kop + kop;
  return res;
}
bool Money::operator==(const Money& c) {
  bool res;
  if ((rub == c.rub) && (kop == c.kop)) {
    res = true;
  }
  else {
    res = false;
  }
  return res;
}
Money::Money(const Money& c) {
  rub = c.rub;
  kop = c.kop;
}
ostream& operator<<(ostream& stream, const Money& c) {
  stream << "rub " << c.rub << " kop " << c.kop << endl;
  return stream;
}
istream& operator>>(istream& stream, Money& c) {
  stream >> c.rub >> c.kop;
  return stream;
}