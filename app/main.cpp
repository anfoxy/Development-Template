#include "Menu.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  string g = "menuu.txt";
  vector <string> n1 = { "File" ,"Main" ,"View" };
  const int k = n1.size();
  Menu a(n1, k, 1, 1, 300);
  cout << a;
  getchar();
  getchar();
  return 0;
}