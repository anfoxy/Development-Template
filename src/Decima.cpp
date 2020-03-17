#include "Decima.h"
ostream& operator<<(ostream& stream, const Decima& c);
istream& operator>>(istream& stream, Decima& c);
Decima::Decima() {
  dec = 0;
  size = 0;
}
Decima::~Decima() {
  delete[] dec;
  size = 0;
}
Decima::Decima(const Decima& c) {
  dec = c.dec;
  size = c.size;
}
Decima::Decima(const char* get) {

  size = strlen(get);
  dec = new unsigned char[size];
  for (int i = size - 1; i >= 0; i--, get++)
  {
    dec[i] = *get;
  }
}
Decima& Decima::operator=(const Decima& c) {
  (*this).dec = c.dec;
  (*this).size = c.size;
  return *this;
}
bool Decima::operator==(const Decima& c) {
  bool res = 0;
  for (int i = 0; (i < size) && (i < c.size) && (res = true); i++) {
    if (dec[i] == c.dec[i]) {
      res = true;
    }
    else {
      res = false;
    }
    return res;
  }
}
Decima Decima::operator+(const Decima& c) {  //не могу решить проблему 
  
  Decima res;
  int *b = new int [size];
  unsigned char k = 0;
  res.size = (size < c.size) ? c.size : size;
  for (int i = 0; i < res.size; i++) {
    b[i] = (dec[i]-'0') +(c.dec[i]-'0') + k;
    k = 0;
    if (b[i] > 9) {
      b[i] = fmod(b[i], 10);
      k = 1;
    }
  }
  
  for (int i = size - 1; i >= 0; i--) {
    res.dec[i] = b[i];
  }
  return res;
}
ostream& operator<<(ostream& stream, const Decima& c) {
  for (int i = c.size - 1; i < c.size; --i)
  {
    stream << c.dec[i];
  }
  return stream;
}
istream& operator>>(istream& stream, Decima& c) {
  for (int i = c.size - 1; i < c.size; --i)
  {
    stream >> c.dec[i];
  }
  return stream;

}
