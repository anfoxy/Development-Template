#include "Decima.h"
ostream& operator<<(ostream& stream, const Decima &d);
istream& operator>>(istream& stream, Decima &d); // ввод из потока


// Констуктор по умолчанию
Decima::Decima()
{
  size = 0;
  dec = NULL;
}
// Констуктор инициализатор
Decima::Decima(int _size) : size(_size)
{
  dec = new unsigned char[size];
}
// Констуктор инициализатор
Decima::Decima(const char* get) {

  size = strlen(get);
  dec = new unsigned char[size];
  for (int i = size - 1; i >= 0; i--, get++)
  {
    dec[i] = *get;
  }
}
// Констуктор копирования
Decima::Decima(const Decima &vec) {
  size = vec.size;
  dec = new unsigned char[size];
  for (int i = 0; i < size; ++i)
    dec[i] = vec.dec[i];
}
// Деструктор
Decima::~Decima() {
  if (dec != NULL)
  {
    delete[] dec;
    dec = NULL;
    size = 0;
  }
}
//вывод в поток
ostream& operator<<(ostream& stream, const Decima &d) {
  for (int i = d.size - 1; i < d.size; --i)
    stream << d.dec[i];
  stream << endl;
  return stream;
}
// операция присваивания	
Decima& Decima::operator=(const Decima &d) {
  if (this != &d) {
    if (size != d.size)
    {
      delete[] dec;
      size = d.size;
      dec = new unsigned char[size];
    }
    for (int i = 0; i < size; ++i)
      dec[i] = d.dec[i];
  }
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
  int s, s1;
  int k = 0;
  s = (size < c.size) ? c.size : size;
  s1 = (size > c.size) ? c.size : size;
  int *b = new int[s];
  if (size < c.size) {

    for (int i = s1; i < s; ++i) {
      dec[i] = '0';
    }
  }
  else {

    for (int i = s1; i < s; ++i) {
      c.dec[i] = '0';
    }
  }
  for (int i = 0; i < s; i++) {
    b[i] = (dec[i] - '0') + (c.dec[i] - '0') + k;
    k = 0;
    if (b[i] > 9) {
      b[i] = fmod(b[i], 10);
      k = 1;
    }
  }if (k == 1) {
    Decima res(s + 1);
    b[s] = 1;
    for (int i = s; i >= 0; i--) {
      res.dec[i] = b[i];
      res.dec[i] = res.dec[i] + 48;
    }
    return res;
  }
  else {
    Decima res(s);
    for (int i = s - 1; i >= 0; i--) {
      res.dec[i] = b[i];
      res.dec[i] = res.dec[i] + 48;
    }
    return res;
  }
}

Decima Decima::operator-(const Decima& c) {
  int s, ms, s1;
  int k = 0;
  s = (size < c.size) ? c.size : size;
  s1 = (size > c.size) ? c.size : size;
  int *b = new int[s];
  if (size < c.size) {
    for (int i = s1; i < s; ++i) {
      dec[i] = '0';
    }
  }
  if (size > c.size) {
    for (int i = s1; i < s; ++i) {
      c.dec[i] = '0';
    }
  }
  Decima res(s);
  ms = (c.dec[s - 1] - '0') - (dec[s - 1] - '0');
  if (ms < 0) {
    for (int i = 0; i < s; i++) {
      b[i] = (dec[i] - '0') - (c.dec[i] - '0') + k;
      k = 0;
      if (b[i] < 0) {
        b[i] = b[i] + 10;
        k = -1;
      }
    }
  }
  else {
    for (int i = 0; i < s; i++) {
      b[i] = (c.dec[i] - '0') - (dec[i] - '0') + k;
      k = 0;
      if (b[i] < 0) {
        b[i] = b[i] + 10;
        k = -1;
      }
    }
  }
  if (ms > 0) {
    cout << "-";
  }
  for (int i = s - 1; i >= 0; i--) {
    res.dec[i] = b[i];
    res.dec[i] = res.dec[i] + 48;
  }

  return res;
}
istream& operator>>(istream& stream, Decima &d) {
  int str;
  stream >> str;
  if (d.size != str)
  {
    if (d.dec != NULL)
      delete[] d.dec;
    d.size = str;
    d.dec = new  unsigned char[str];
  }
  for (int i = d.size - 1; i < d.size; --i)
    stream >> d.dec[i];
  return stream;
}