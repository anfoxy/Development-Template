#include "Menu.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  string g = "menuu.txt";
  vector <string> n1 = { "to change the window size" ,"minimize window" ,"exit"};
  const int k = n1.size();
  Menu a(n1, k, 1, 1, 700);
  punktmenu(a);
  getchar();
  getchar();
  return 0;
}