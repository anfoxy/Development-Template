#ifndef INCLUDE_Menu_H_
#define INCLUDE_Menu_H_
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;
struct coor {
  int xCor;
  int yCor;
  int size;
};
class Menu {
private:
  int kol;
  vector <string> nazvan;
  int xCor;
  int yCor;
  int size;
  coor Cor;
public:
  friend void doSomething(const Menu &d, int n);
  friend int punktmenu(const Menu &d);
  friend void razm(const Menu &c);
  friend ostream& operator<<(ostream& stream, const Menu &d);//
  Menu(vector <string> naz, int k, int x, int y, int d);
  Menu(string n);
};

#endif  // INCLUDE_Menu_H_
