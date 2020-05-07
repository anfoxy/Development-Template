#include "Credit.h"
#include "ProcCenter.h"

void Credit::poisk(ProcCenter & d) {
  bool t = false;
  for (int i = 0; i < d.pers.size(); i++) {
    if ((d.pers[i].parol == dann.porol) && (d.pers[i].schet == dann.schet)) { 
      nomer = i;
      t = true;
    }
  }
  if (t == false) {
    cout << "Неверный счет или пароль" << endl;
    cout << "Нажмите 1 если хотите попробовать снова" << endl;
    cout << "Нажмите 2 если хотите зарегистрироваться" << endl;
    int v=-1;
    while (v < 1 || v > 2) {
      cin >> v;
    }
    switch (v) {
    case 1:  Vhod(d);                               break;
    case 2:  d.AddPers(); nomer=d.pers.size()-1;    break;
    }
  }
}
void Credit::podasN(ProcCenter &c) {
  if (c.pers[nomer].kol == 0) {
    cout << "У вас нет кредита!" << endl;
  }
  else {
    c.pers[nomer].kol = c.pers[nomer].kol - 1;
    c.pers[nomer].money = c.pers[nomer].money - c.pers[nomer].plata_po_kredity;
    cout << "Выплата прошла успешно..." << endl;
    if (c.pers[nomer].kol == 0) {
      c.pers[nomer].kredinf = false;
      c.pers[nomer].vzkredit = 0;
      c.pers[nomer].plata_po_kredity = 0;
    }
  }
  viborC(c);
}
void Credit::podasV(ProcCenter &c) {
  if (c.pers[nomer].kol == 0) {
    cout << "У вас нет кредита!" << endl;
  }
  else {
    c.pers[nomer].money = (c.pers[nomer].money - (c.pers[nomer].plata_po_kredity * c.pers[nomer].kol));
    c.pers[nomer].kol = 0;
    c.pers[nomer].kredinf = false;
    c.pers[nomer].vzkredit = 0;
    c.pers[nomer].plata_po_kredity = 0;
    cout << "Выплата прошла успешно..." << endl;
  }
  viborC(c);
}

void Credit::Vhod(ProcCenter &c) {
  cout << "Пароль: ";
  cin >> dann.porol;
  cout << "Ваш номер счета: ";
  cin >> dann.schet;
  poisk(c);
  viborC(c);
}
void Credit::VZCredit(ProcCenter &c) {
  if (c.pers[nomer].kredinf == false) {
    cout << "У вас нет кредита" << endl;
    cout << "Имя:" << endl;
    cout << c.pers[nomer].persName << endl;
    cout << "Фвмилия:" << endl;
    cout << c.pers[nomer].persFamil << endl;
    cout << "Отчество:" << endl;
    cout << c.pers[nomer].persOtchestvo << endl;
    cout << "Ваш счет:" << endl;
    cout << c.pers[nomer].money << endl;
  }
  else {
    cout << "Данные по кредиту" << endl;
    cout << "Имя:" << endl;
    cout << c.pers[nomer].persName << endl;
    cout << "Фвмилия:" << endl;
    cout << c.pers[nomer].persFamil << endl;
    cout << "Отчество:" << endl;
    cout << c.pers[nomer].persOtchestvo << endl;
    cout << "Отчество:" << endl;
    cout << c.pers[nomer].persOtchestvo << endl;
    cout << "Ваш счет" << endl;
    cout << c.pers[nomer].money << endl;
    cout << "Вы взяли в кредит:" << endl;
    cout << c.pers[nomer].vzkredit << endl;
    cout << "Ежемесечная выплата:" << endl;
    cout << c.pers[nomer].plata_po_kredity << endl;
    cout << "Выплат осталось:" << endl;
    cout << c.pers[nomer].kol << endl;
  }
  viborC(c);
}
int Credit::proverka(ProcCenter &c,int kredit) {
  int odobrenie=-1;
  if ((kredit*6) < c.pers[nomer].money) {
    odobrenie = 1;
  }
  return odobrenie;
}
int raschetC(int sum,int srok,int proc) {
  double i = (double)proc / 100/12;
  double m = srok * 12;
  double kredit = i/(1-(pow(1 + i, -m)));
  kredit = sum * kredit;
  return (int)kredit;
}
void Credit::polkredit(ProcCenter &c) {
  if (c.pers[nomer].kredinf == true) {
    cout << "У вас есть кредит!" << endl;
  }
  else {
    int summ;
    int _kredit, v=-1;
    int odob = -1;
    cout << "Введите сумму кредита,которую вы хотите взять" << endl;
    cin >> summ;
    if (summ < 1 || summ > 3000000) throw std::logic_error("Input error: wrong number!");
    cout << endl;
    cout << "Выбирите срок" << endl;
    cout << "1 - 1 год" << endl;
    cout << "2 - 2 года " << endl;
    cout << "3 - 3 года" << endl;
    cout << "4 - 5 лет" << endl;
    cout << "5 - 15 лет" << endl;
    std::cout << "-------------------------------------------------" << std::endl;
    while (v < 1 || v > 5) {
      cin >> v;
    }
    switch (v) {
    case 1: _kredit = malo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "кредит  одобрен" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 12;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "кредит был не одобрен" << endl;
      break;
    case 2: _kredit = sred(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "кредит  одобрен" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 24;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "кредит был не одобрен" << endl;
      break;
    case 3: _kredit = mnogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "кредит  одобрен" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 36;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "кредит был не одобрен" << endl;
      break;
    case 4: _kredit = ogogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "кредит  одобрен" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 60;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "кредит был не одобрен" << endl;
      break;
    case 5: _kredit = Wow(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) {
        cout << "кредит  одобрен" << endl;
        c.pers[nomer].plata_po_kredity = _kredit;
        c.pers[nomer].vzkredit = summ;
        c.pers[nomer].kol = 180;
        c.pers[nomer].money = c.pers[nomer].money + summ;
        c.pers[nomer].kredinf = true;
      }
      else  cout << "кредит был не одобрен" << endl;
      break;
    }
  }
  viborC(c);

}

int Credit::malo(int summ,ProcCenter &c) {
  int  proc;
  int srok=1;
  if (summ < 100000) {
    proc = 16;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 15;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 13;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 12;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
 /* 1 - до 100 тыс
    2 - от 100 до 500 тыс
    3 - от 500 тыс до 1 млн
    4 - от 1 млн до 3 млн*/
}
int Credit::sred(int summ, ProcCenter &c) {
  int proc;
  int srok = 2;
  if (summ < 100000) {
    proc = 15;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 14;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 13;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 12;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}
int Credit::mnogo(int summ, ProcCenter &c) {
  int  proc;
  int srok = 3;
  if (summ < 100000) {
    proc = 15;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 13;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 12;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 9;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}
int Credit::ogogo(int summ, ProcCenter &c) {
  int  proc;
  int srok = 5;
  if (summ < 100000) {
    proc = 14;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 13;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 12;
      }
      else {
        if (summ >= 1000000 && summ <= 3000000) {
          proc = 9;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}
int Credit::Wow(int summ, ProcCenter &c) {
  int  proc;
  int srok = 15;
  if (summ < 100000) {
    proc = 13;
  }
  else {
    if (summ >= 100000 && summ < 500000) {
      proc = 12;
    }
    else {
      if (summ >= 500000 && summ < 1000000) {
        proc = 9;
      }
      else {
        if (summ >= 1000000 && summ <=3000000) {
          proc = 8;
        }
      }
    }
  }
  int kredit;
  kredit = raschetC(summ, srok, proc);
  return kredit;
}

void Credit::infCredit(ProcCenter &c) {
  if (c.pers[nomer].kredinf == true) {
    cout << "У вас есть кредит!" << endl;
  }
  else {
    int summ;
    cout << "Введите сумму кредита,которую вы хотите взять" << endl;
    cin >> summ;
    if (summ < 1 || summ > 3000000) throw std::logic_error("Input error: wrong number!");
    int v=-1;
    int odob = -1;
    int _kredit;
    cout << endl;
    cout << "Выбирите срок" << endl;
    cout << "1 - 1 год" << endl;
    cout << "2 - 2 года " << endl;
    cout << "3 - 3 года" << endl;
    cout << "4 - 5 лет" << endl;
    cout << "5 - 15 лет" << endl;
    std::cout << "-------------------------------------------------" << std::endl;
    while (v < 1 || v > 5) {
      cin >> v;
    }
    switch (v) {
    case 1: _kredit = malo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "кредит был бы одобрен" << endl; }
      else  cout << "кредит был бы не одобрен" << endl;
      cout << "Выплата составила бы:  ";
      cout << _kredit;
      cout << "  рублей в месяц" << endl; break;
    case 2: _kredit = sred(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "кредит был бы одобрен" << endl; }
      else  cout << "кредит был бы не одобрен" << endl;
      cout << "Выплата составила бы:  ";
      cout << _kredit;
      cout << "  рублей в месяц" << endl; break;
    case 3: _kredit = mnogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "кредит был бы одобрен" << endl; }
      else  cout << "кредит был бы не одобрен" << endl;
      cout << "Выплата составила бы:  ";
      cout << _kredit;
      cout << "  рублей в месяц" << endl; break;
    case 4: _kredit = ogogo(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "кредит был бы одобрен" << endl; }
      else  cout << "кредит был бы не одобрен" << endl;
      cout << "Выплата составила бы:  ";
      cout << _kredit;
      cout << "  рублей в месяц" << endl; break;
    case 5: _kredit = Wow(summ, c);
      odob = proverka(c, _kredit);
      if (odob == 1) { cout << "кредит был бы одобрен" << endl; }
      else  cout << "кредит был бы не одобрен" << endl;
      cout << "Выплата составила бы:  ";
      cout << _kredit;
      cout << "  рублей в месяц" << endl; break;
    }
  }
  viborC(c);
}
void Credit::infCreditNAL(ProcCenter &c) {
  if (c.pers[nomer].kredinf == false) {
    cout << "У вас нет кредита" << endl;
  }
  else {
    cout << "У вас есть кредит" << endl;
  }
  viborC(c);
}
void PrintMenut()
{
  cout << endl;
  cout << "Выбирите действие" << endl;
  cout << "1 - Сменить пользователя" << endl;
  cout << "2 - Показать информацию о кредите" << endl;
  cout << "3 - Проверить наличие кредита" << endl;
  cout << "4 - Проверить возможность взять кредит" << endl;
  cout << "5 - Получить выбранный кредит" << endl;
  cout << "6 - Погасить начисления по кредиту" << endl;
  cout << "7 - Погасить кредит" << endl;
  cout << "8 - Выйти" << endl;
  std::cout << "-------------------------------------------------" << std::endl;
}
void Credit::viborA(ProcCenter &d) {
  cout << "Вход в систему" << endl;;
  Vhod(d);   

}
void Credit::viborC (ProcCenter &d) {
  PrintMenut();
  int v=-1;
  while (v < 1 || v > 8) {
    cin >> v;
  }
  switch (v) {
  case 1: Vhod(d);           break;
  case 2: VZCredit(d);       break;
  case 3: infCreditNAL(d);   break;
  case 4: infCredit(d);      break;
  case 5: polkredit(d);      break;
  case 6: podasN(d);         break;
  case 7: podasV(d);         break;
  case 8: exit(0);           break;
  }
}

