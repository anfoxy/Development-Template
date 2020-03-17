#ifndef INCLUDE_Decima_H_
#define INCLUDE_Decima_H_

#include <iostream>
#include <stdexcept>


using namespace std;
class Decima {
private:
  size_t size;
  unsigned char* dec;
public:

  Decima();
  ~Decima();
  Decima(const Decima& c);
  Decima(const char* get);
  Decima operator+(const Decima& c);
  bool operator == (const Decima & c);
  Decima& operator = (const Decima & c);
  friend ostream& operator<<(ostream& stream, const Decima& c);
  friend istream& operator>>(istream& stream, Decima& c);
};
#endif  // INCLUDE_Decima_H_
