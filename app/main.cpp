#include "Credit.h"
#include "ProcCenter.h"
int main() {
  setlocale(LC_CTYPE, "Russian");
  inf s1("Nastya","Kazhaeva","Vladimirovna","1234",10000);
  ProcCenter h(s1);
  Credit n;
  n.viborA(h);
  getchar();
  getchar();
  return 0;
}