
#include <iostream>

#include "Decima.h"

int main() {
  Decima a = "1111111118";
  Decima b = "2222222226";
  Decima c;
  c = a + b;
  cout << endl;
  cout << a;
  cout << endl;
  cout << b;
  cout << endl;
 
  if (a == b) {
    cout << "ravno ";
  }
  else {
    cout << "ne ravno ";
  }
  getchar();
  getchar();
  return 0;
}