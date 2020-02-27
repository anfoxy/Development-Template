#ifndef INCLUDE_ClassMoney_H_
#define INCLUDE_ClassMoney_H_
#include <iostream>
#include <stdexcept>
using namespace std;

class Money {
public:
  Money();
  ~Money();
  Money(int _rub, int _kop);
  Money(const Money& c);
  Money(int d);
  Money& operator = (const Money & c);
  Money operator + (const Money & c);
  bool operator == (const Money & c);
  Money operator - (const Money & c);
  Money operator * (double c);
  Money operator / (double c);
  friend ostream& operator<<(ostream& stream, const Money& c);
  friend istream& operator>>(istream& stream, Money& c);
private:
  int rub;
  double kop;
};

#endif  // INCLUDE_ClassMoney_H_
