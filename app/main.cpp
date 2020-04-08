#include "Decima.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  Decima a = "43456";
  Decima b = "111";
  Decima c, f;
  cout << "a =  " ;
  cout << a;
  cout << "b =  ";
  cout << b;
  cout << "введите сначала количество цифр в числе, а потом цифры" << endl;
  cin >> f;
  cout << "ваше число =  ";
  cout << f;
  cout << "a - b= " ;
  c = a - b;
  cout << c;
  cout << "a + b= " ;
  c = a + b;
  cout << c;
  
  if (a == b) {
    cout << " a равно b";
  }
  else {
    cout << "a не равно b";
  }
  getchar();
  getchar();
  return 0;
}