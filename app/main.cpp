#include "ClassMoney.h"


using namespace std;
int main() {
  Money c1, c2(5, 10), c3(6, 10), c4, c5, c6, c7;
  c1 = c2;
  c6 = c2 * 8;
  c5 = c2 - c3;
  c7 = c2 + c3;
  c4 = c2 / 2;
  cout << "c1 = c2 = " << c1;
  cout << "c2= " << c2;
  cout << "c3= " << c3;
  cout << "c2 * 8 = " << c6;
  cout << "c2 - c3 = " << c5;
  cout << "c2+c3 = " << c7;
  cout << "c2/2= " << c4;
  if (c2 == c2) {
    cout << c2 << "ravno " << c2;
  }
  else {
    cout << c2 << "ne ravno " << c2;
  }
  getchar();
  getchar();
  return 0;
}