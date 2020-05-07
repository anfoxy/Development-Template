#ifndef INCLUDE_Credit_H_
#define INCLUDE_Credit_H_
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
struct po{
  string schet;
  string porol;
};
class Credit {
private:
  po dann;
  int nomer=0;
public:
  friend class ProcCenter;
  friend class inf;
  void poisk(ProcCenter &d);
  Credit() {}
  ~Credit() {}
  int Credit::proverka(ProcCenter &c,int kredit);
  void polkredit(ProcCenter &c);
  int Wow(int summ, ProcCenter &c);
  int malo(int summ, ProcCenter &c);
  int sred(int summ, ProcCenter &c);
  int mnogo(int summ, ProcCenter &c);
  int ogogo(int summ, ProcCenter &c);
  void VZCredit(ProcCenter &c);
  void infCredit(ProcCenter &c);
  void infCreditNAL(ProcCenter &c);
  void viborA(ProcCenter &d);
  void viborC(ProcCenter &d);
  void Vhod( ProcCenter &d);
  void podasN(ProcCenter &d);
  void podasV(ProcCenter &d);
};
int raschetC(int sum, int srok, int proc);
#endif  // INCLUDE_Credit_H_
