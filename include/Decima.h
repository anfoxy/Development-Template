#ifndef INCLUDE_Decima_H_
#define INCLUDE_Decima_H_

#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;
class Decima {
private:
  size_t size;
  unsigned char* dec;
public:
  Decima();
  explicit Decima(int _size);
  Decima(const char* get);
  Decima(const Decima &d);//
  ~Decima();
  Decima& operator=(const Decima &d);//
  friend bool Decima::operator==(const  Decima& left, const  Decima& right) {//
    bool res = 0;
    for (int i = 0; (i < left.size) && (i < right.size) && (res = true); i++) {
      if (left.dec[i] == right.dec[i]) {
        res = true;
      }
      else {
        res = false;
      }
      return res;
    }
  }
  Decima operator+(const Decima& c);//
  Decima operator-(const Decima& c);//
  friend ostream& operator<<(ostream& stream, const Decima &d);//
  friend istream& operator>>(istream& stream, Decima &d);//
};
#endif  // INCLUDE_Decima_H_
