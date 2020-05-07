#include "ProcCenter.h"

int n = 1;
vector<inf> date;
inf::inf(string _name, string _famil, string _otch, string _parol,int _money) {
  string persName, persFamil, persOtchestvo, parol;
  int money;
   persName = _name;
   persFamil = _famil;
   persOtchestvo = _otch;
   money = _money;
   if (money < 1 || money > 3000000) throw std::logic_error("Input error: wrong number!");
   char schet[5];
   if (n < 10) {
     schet[0] = '0';
     schet[1] = '0';
     schet[2] = '0';
     schet[3] = n+'0';
     schet[4] = '\0';
   } else {
     if ((n >= 10) && (n<100)){
     int k = fmod(n, 10);
     int j = n/10;
     schet[0] = '0';
     schet[1] = '0';
     schet[2] = j + '0';
     schet[3] = k + '0';
     schet[4] = '\0';
     }
     else {
       if (n >= 100 && n < 1000) {
         int j2 = fmod(n, 100);
         j2 = j2 / 10;
         int j3 = fmod(n, 10);
         int j = n / 100;
         schet[0] = '0';
         schet[1] = j + '0';
         schet[2] = j2 + '0';
         schet[3] = j3 + '0';
         schet[4] = '\0';
       }
       else {
         if (n >= 1000 && n < 10000) {
           int j = n / 1000;
           int j1 = fmod(n/100, 10);
           int j2 = fmod(n / 10, 10);
           int j3 = fmod(n, 10);
           schet[0] = j + '0';
           schet[1] = j1 + '0';
           schet[2] = j2 + '0';
           schet[3] = j3 + '0';
           schet[4] = '\0';
         }
         else {
           exit(0);
         }
       }
     }
   }
   n++;
   parol = _parol;
  bool kredinf=false;
  int plata=0, kredit=0;
  SetInf(persName, persFamil, persOtchestvo, parol, money, kredinf, schet,plata,kredit);
}
ProcCenter::ProcCenter(const inf &d) {
  date.push_back(d);
  SetINF(date);
  date.pop_back();
}

void ProcCenter::AddPers() {
  system("cls");
  string persName, persFamil, persOtchestvo, parol;
  int money;
  char schet[4];
  cout << endl;

  cout << endl;
  cout << "Имя: ";
  cin >> persName;
  cout << endl;
  cout << "Фамилия: ";
  cin >> persFamil;
  cout << endl;
  cout << "Отчество: ";
  cin >> persOtchestvo;
  cout << endl;
  cout << "Пароль: ";
  cin >> parol;
  cout << endl;
  cout << "Сколько денег на счету: ";
  cin >> money;
  cout << endl;
  inf bufNabl(persName, persFamil, persOtchestvo, parol, money);
  pers.push_back(bufNabl);
  cout << "Ваш номер счета: ";
  cout << pers[pers.size()-1].schet;
  cout << endl;
  cout << "----------------------------------------------------------------" << endl;
}
