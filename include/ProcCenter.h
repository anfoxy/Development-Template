#ifndef INCLUDE_ProcCenter_H_
#define INCLUDE_ProcCenter_H_
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
class inf {
public:
  friend class ProcCenter;
  friend class Credit;
  inf() {}
  ~inf() {}
  inf(string _name, string _famil, string _otch, string _parol, int _money);
  void SetInf(string _name, string _famil, string _otch, string _parol, int _money, bool cred, char* scet,int plata,int kredit) {
    persName = _name;
    persFamil = _famil;
    persOtchestvo = _otch;
    parol = _parol;
    money = _money;
    schet = string(scet);
    kredinf = cred;
    plata_po_kredity= plata;
    vzkredit= kredit;
    kol = 0;
  }
private:
  string persName;
  string persFamil;
  string persOtchestvo;
  int money;
  int plata_po_kredity;
  int vzkredit;
  int kol;
  string schet;
  string parol;
  bool kredinf;
};
class ProcCenter {
public:
  friend class Credit;
  friend class inf;
  ProcCenter() {}
  ~ProcCenter() {}
  void setCredit(int nom, int _kredit, int summ, int kol);
  void AddPers();
  ProcCenter(const inf &d);
  void SetINF(vector <inf> pers1) {
    pers = pers1;
  }
private:
  vector <inf> pers;
};

#endif  // INCLUDE_ProcCenter_H_
