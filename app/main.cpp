#include "Menu.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  const int k = 3;
  string g = "menuu.txt";
  vector <string> n1 = { "One", "Two", "Three" };
  Menu a(n1, k, 0, 0, 300);
  cout << a;
  getchar();
  getchar();
  return 0;
}