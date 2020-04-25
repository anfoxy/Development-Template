#include "FloorScales.h"
ostream& operator<<(ostream& stream, const SForFile h);


vector <FloorScales> pers;
vector <FloorScales> date;

FloorScales::FloorScales(string _name, int _day, int _mes, int _year, int _ves) {
  string sbuf;
  int day, mes , year, ves ;
  FloorScales bufPers;
  FloorScales bufNabl;
  sbuf= _name;
  bufPers.SetName(sbuf);

    day= _day;
    if (day < 1 || day > 31) throw std::logic_error("Input error: wrong number!");
    mes= _mes;
    if (mes < 1 || mes > 12) throw std::logic_error("Input error: wrong number!");
    year= _year;
    if (year < 1900 || year > 2020) throw std::logic_error("Input error: wrong number!");
    ves= _ves;
    if (ves < 1 || ves > 1000) throw std::logic_error("Input error:wrong number!");
  bufNabl.SetNabl(day, mes, year, ves);
  date.push_back(bufNabl);
  bufPers.SetNABL(date);

  pers.push_back(bufPers);
  date.pop_back();
}
void AddFloorScales() {
  system("cls");
  int day = -1, mes = -1, year = -1, ves = -1;
  string sbuf;
  FloorScales bufPers;
  FloorScales bufNabl;
  cout << endl;

  cout << endl;
  cout << "Имя: ";
  cin >> sbuf;
  bufPers.SetName(sbuf);

  cout << endl;
  cout << "Дата: ";
  cout << endl;
  cout << "День (от 1 до 31): ";
  while (day < 1 || day > 31) {
    cin >> day;
  }
  if (day < 1 || day > 31) throw std::logic_error("Input error:wrong number!");
  cout << "месяц(от 1 до 12): ";
  while (mes < 1 || mes >12) {
    cin >> mes;
  }
  if (mes < 1 || mes > 12) throw std::logic_error("Input error:wrong number!");
  cout << "год (от 1900 до 2020): ";
  while (year < 1900 || year > 2020) {
    cin >> year;
  }
  cout << endl;
  if (year < 1900 || year > 2020) throw std::logic_error("Input error:wrong number!");
  cout << "вес(положительное число):";
  while (ves < 1 || ves > 1000) {
    cin >> ves;
  }
  if (ves < 1 || ves > 1000) throw std::logic_error("Input error: wrong number!");
  bufNabl.SetNabl(day, mes, year, ves);
  date.push_back(bufNabl);
  bufPers.SetNABL(date);

  pers.push_back(bufPers);
  date.pop_back();
  cout << "----------------------------------------------------------------" << endl;
  vibor();
}
void vivodpers() {
  cout << "выберете человека" << endl;
  for (unsigned int n = 0; n < pers.size(); n++)
  {
    std::cout << "-------------------------------------------------" << std::endl;
    cout << (n + 1) << endl;
    pers[n].PrintName();
    std::cout << "-------------------------------------------------" << std::endl;
  }

}

void AddNabl() {
  system("cls");
  int v = -1;
  vivodpers();
  while (v < 1 || v > pers.size()) {
    cin >> v;
  }
  switch (v) {
  case 1: pers[0].addnablpers(); break;
  case 2: pers[1].addnablpers(); break;
  case 3: pers[2].addnablpers(); break;
  case 4: pers[3].addnablpers(); break;
  case 5: pers[4].addnablpers(); break;
  }
  vibor();
}
void FloorScales::addnablpers() {
  system("cls");
  FloorScales bufNabl;
  int day = -1, mes = -1, year = -1, ves = -1, n;
  cout << endl;
  cout << "Дата: ";
  cout << endl;
  cout << "День(от 1 до 31): ";
  while (day < 1 || day > 31) {
    cin >> day;
  }
  if (day < 1 || day > 31) throw std::logic_error("Input error:wrong number!");
  cout << "месяц(от 1 до 12): ";
  while (mes < 1 || mes >12) {
    cin >> mes;
  }
  if (mes < 1 || mes > 12) throw std::logic_error("Input error:wrong number!");
  cout << "год (положительное число): ";
  while (year < 1900 || year > 2020) {
    cin >> year;
  }
  if (year < 1900 || year > 2020) throw std::logic_error("Input error:wrong number!");
  cout << endl;
  cout << "вес(положительное число):";
  while (ves < 1 || ves > 1000) {
    cin >> ves;
  }
  if (ves < 1 || ves > 1000) throw std::logic_error("Input error:wrong number!");
  bufNabl.SetNabl(day, mes, year, ves);
  nabl.push_back(bufNabl);
  for (unsigned int n = 0; n < nabl.size() - 1; n++)
  {
    if (
      nabl[n].persDataDay == nabl[nabl.size() - 1].persDataDay &&
      nabl[n].persDataMes == nabl[nabl.size() - 1].persDataMes  &&
      nabl[n].persDataYear == nabl[nabl.size() - 1].persDataYear
      ) {
      cout << "Такая дата есть! нажмите 1 чтобы перезаписать! (иначе данные будут не сохранены)";
      cin >> n;
      if (n == 1) {
        nabl[n].persVes = nabl[nabl.size() - 1].persVes;
        nabl.pop_back();
      }
      else {
        nabl.pop_back();
      }

    }
  }
}
void FloorScales::input() {
  int  keyMes, keyYear;
  cout << "введите год и месяц" << endl;
  cout << "месяц ";
  cin >> keyMes;
  if (keyMes < 1 || keyMes > 12) throw std::logic_error("Input error: wrong number!");
  cout << "год ";
  if (keyYear < 1900 || keyYear > 2020) throw std::logic_error("Input error:wrong number!");
  bool t = true;

  stry.Mes = keyMes;
  stry.Year = keyYear;
}

int FloorScales::sredmes(int keyMes, int keyYear) {
  int resves, ves = 0, k = 0;

  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    if (
      nabl[n].persDataMes == keyMes &&
      nabl[n].persDataYear == keyYear
      ) {
      k++;
      ves = nabl[n].persVes + ves;
    }
  }
  resves = ves / k;
  return resves;
}

void FloorScales::sred_with_output(int keyMes, int keyYear) {
  int resves = sredmes(keyMes, keyYear);
  if (resves == 0) {
    cout << "Данной даты нет";
  }
  else {
    cout << "средний вес за данный месяц: ";
    cout << resves;
  }
 
}
void FloorScales::sredmes() {
  input();
  sred_with_output(stry.Mes,stry.Year);
}

void FloorScales::sredv() {
  int   ves = 0, k = 0;
  double resves;
  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    k++;
    ves = nabl[n].persVes + ves;
  }
  cout << "средний вес за все время: ";
  resves = ves / k;
  cout << resves;
}
void SredVes() {
  int v1 = -1, v2 = -1;
  cout << "1 - найти средний вес человека в выбранном месяце " << endl;
  cout << "2 - найти средний вес человека за всю историю " << endl;
  while (v1 < 1 || v1 >2) {
    cin >> v1;
  }
  switch (v1) {
  case 1:
    vivodpers();
    while (v2 < 1 || v2 > pers.size()) {
      cin >> v2;
    }
    switch (v2) {
    case 1:
      pers[0].sredmes();
      break;
    case 2:
      pers[1].sredmes();
      break;
    case 3:
      pers[2].sredmes();
      break;
    case 4:
      pers[3].sredmes();
      break;
    case 5:
      pers[4].sredmes();
      break;
    }
    break;
  case 2:
    vivodpers();
    while (v2 < 1 || v2 > pers.size()) {
      cin >> v2;
    }
    switch (v2) {
    case 1:
      pers[0].sredv();
      break;
    case 2:
      pers[1].sredv();
      break;
    case 3:
      pers[2].sredv();
      break;
    case 4:
      pers[3].sredv();
      break;
    case 5:
      pers[4].sredv();
      break;
    }
    break;
  }
  vibor();
}
int FloorScales::minmes(int keyMes, int keyYear) {
  int ves = 999999999;
  for (unsigned int n = 0; n < nabl.size(); n++) {
    if (
      nabl[n].persDataMes == keyMes &&
      nabl[n].persDataYear == keyYear
      ) {
      if (ves > nabl[n].persVes) {
        ves = nabl[n].persVes;
      }
    }
  }

  return ves;
}

void FloorScales::minmes_with_output(int keyMes, int keyYear) {
  int ves = minmes(keyMes, keyYear);
  if (ves == 999999999) {
    cout << "Данной даты нет";
  }
  else {
    cout << "Минимальный вес за данный месяц: " << ves;
  }
  
}
void FloorScales::minmes() {
  input();
  minmes_with_output(stry.Mes, stry.Year);
}
void FloorScales::minv() {
  int  ves = 999999999;
  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    if (ves > nabl[n].persVes) {
      ves = nabl[n].persVes;
    }
  }
  cout << "minimum weight for all time: ";
  cout << ves << endl;
 
}
void MinVes() {
  int v1 = -1, v2 = -1;
  cout << "1 - найти минимальный вес человека в выбранном месяце " << endl;
  cout << "2 - найти минимальный вес человека за всю историю " << endl;
  while (v1 < 1 || v1 >2) {
    cin >> v1;
  }
  switch (v1) {
  case 1:
    vivodpers();
    while (v2 < 1 || v2 > pers.size()) {
      cin >> v2;
    }
    switch (v2) {
    case 1:
      pers[0].minmes();
      break;
    case 2:
      pers[1].minmes();
      break;
    case 3:
      pers[2].minmes();
      break;
    case 4:
      pers[3].minmes();
      break;
    case 5:
      pers[4].minmes();
      break;
    }
    break;
  case 2:
    vivodpers();
    while (v2 < 1 || v2 > pers.size()) {
      cin >> v2;
    }
    switch (v2) {
    case 1:
      pers[0].minv();
      break;
    case 2:
      pers[1].minv();
      break;
    case 3:
      pers[2].minv();
      break;
    case 4:
      pers[3].minv();
      break;
    case 5:
      pers[4].minv();
      break;
    }
    break;
  }
  vibor();
}
int FloorScales::maxmes1(int keyMes, int keyYear) {
  int resves, ves = -1;

  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    if (
      nabl[n].persDataMes == keyMes &&
      nabl[n].persDataYear == keyYear
      ) {
      if (ves < nabl[n].persVes) {
        ves = nabl[n].persVes;

      }
    }
  }

  return ves;
}

void FloorScales::max_with_output(int keyMes, int keyYear) {
  int ves = maxmes1(keyMes, keyYear);
  if (ves == -1) {
    cout << "Данной даты нет";
  }
  else {
    cout << "максимальный вес за данный месяц: ";
    cout << ves;
  }

}
void FloorScales::maxmes() {
  input();
  max_with_output(stry.Mes, stry.Year);
}

void FloorScales::maxv() {
  int  ves = -1;
  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    if (ves < nabl[n].persVes) {
      ves = nabl[n].persVes;
    }
  }
  cout << "максимальный вес за все время: ";
  cout << ves;


}
void MaxVes() {
  int v1 = -1, v2 = -1;
  cout << "1 - найти максимальный вес человека в выбранном месяце " << endl;
  cout << "2 - найти максимальный вес человека за всю историю " << endl;
  while (v1 < 1 || v1 >2) {
    cin >> v1;
  }
  switch (v1) {
  case 1:
    vivodpers();
    while (v2 < 1 || v2 > pers.size()) {
      cin >> v2;
    }
    switch (v2) {
    case 1:
      pers[0].maxmes();
      break;
    case 2:
      pers[1].maxmes();
      break;
    case 3:
      pers[2].maxmes();
      break;
    case 4:
      pers[3].maxmes();
      break;
    case 5:
      pers[4].maxmes();
      break;
    }
    break;
  case 2:
    vivodpers();
    while (v2 < 1 || v2 > pers.size()) {
      cin >> v2;
    }
    switch (v2) {
    case 1:
      pers[0].maxv();
      break;
    case 2:
      pers[1].maxv();
      break;
    case 3:
      pers[2].maxv();
      break;
    case 4:
      pers[3].maxv();
      break;
    case 5:
      pers[4].maxv();
      break;
    }
    break;
  }
  vibor();
}

void FloorScales::vvodkeyDate() {
  
  cout << endl << "Введите нужную дату" << endl;
  int  keyMes, keyYear, keyDay;
  cout << "введите год и месяц" << endl;
  cout << "день ";
  cin >> keyDay;
  if (keyDay < 1 || keyDay > 31) throw std::logic_error("Input error: wrong number!");
  cout << "месяц ";
  cin >> keyMes;
  if (keyMes < 1 || keyMes > 12) throw std::logic_error("Input error: wrong number!");
  cout << "год ";
  cin >> keyYear;
  if (keyYear < 1900 || keyYear > 2020) throw std::logic_error("Input error: wrong number!");
  stry.Day = keyDay;
  stry.Mes = keyMes;
  stry.Year = keyYear;
}
void FloorScales::Poisk() {
 
  vvodkeyDate();
  bool t = true;
  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    if (
      nabl[n].persDataDay == stry.Day &&
      nabl[n].persDataMes == stry.Mes &&
      nabl[n].persDataYear == stry.Year
      ) {
      cout << "Вес : ";
      cout << nabl[n].persVes;
      t = false;
    }
  }
  if (t == true) {
    cout << "Данной даты нет";
  }
  vibor();
}
void FloorScales::Mes() {
  std::cout << "-------------------------------------------------" << std::endl;
  cout << " Даты наблюдения " << endl;
  std::cout << "-------------------------------------------------" << std::endl;
  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    cout << (n + 1) << endl;
    cout << nabl[n].persDataDay << ".";
    cout << nabl[n].persDataMes << ".";
    cout << nabl[n].persDataYear << endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }
}
void dateVes() {
  system("cls");
  int v = -1;
  vivodpers();
  while (v < 1 || v > pers.size()) {
    cin >> v;
  }
  switch (v) {
  case 1:
    pers[0].Mes();
    pers[0].Poisk();
    break;
  case 2:
    pers[1].Mes();
    pers[1].Poisk();
    break;
  case 3:
    pers[2].Mes();
    pers[2].Poisk();
    break;
  case 4:
    pers[3].Mes();
    pers[3].Poisk();
    break;
  case 5:
    pers[4].Mes();
    pers[4].Poisk();
    break;
  }
}
void FloorScales::Print()
{

  cout << "Имя" << endl;
  cout << persName.c_str() << endl;
  cout << "День" << endl;
  cout << nabl[0].persDataDay << endl;
  cout << "Месяц" << endl;
  cout << nabl[0].persDataMes << endl;
  cout << "Год" << endl;
  cout << nabl[0].persDataYear << endl;
  cout << "Начальный вес" << endl;
  cout << nabl[0].persVes << endl;
}

void FloorScales::PrintNabl()
{
  system("cls");
  for (unsigned int n = 0; n < nabl.size(); n++)
  {
    std::cout << "-------------------------------------------------" << std::endl;
    cout << (n + 1) << ")" << endl;
    cout << "День" << endl;
    cout << nabl[n].persDataDay << endl;
    cout << "Месяц" << endl;
    cout << nabl[n].persDataMes << endl;
    cout << "Год" << endl;
    cout << nabl[n].persDataYear << endl;
    cout << "вес" << endl;
    cout << nabl[n].persVes << endl;
    std::cout << "-------------------------------------------------" << std::endl;
  }

}
void FloorScales::PrintName()
{
  cout << "Имя" << endl;
  cout << persName.c_str() << endl;
}
void PrintPers() {

  int v = -1;
  vivodpers();
  while (v < 1 || v > pers.size()) {
    cin >> v;
  }
  switch (v) {
  case 1: pers[0].PrintNabl();
    break;
  case 2: pers[1].PrintNabl(); break;
  case 3: pers[2].PrintNabl(); break;
  case 4: pers[3].PrintNabl(); break;
  case 5: pers[4].PrintNabl(); break;
  }
  vibor();
}
void PrintAll()
{
  system("cls");

  cout << "                   Члены семьи и начальные показания " << std::endl;

  for (unsigned int n = 0; n < pers.size(); n++)
  {
    std::cout << "-------------------------------------------------" << std::endl;
    cout << (n + 1) << ")" << endl;
    pers[n].Print();
    std::cout << "-------------------------------------------------" << std::endl;
  }

  cout << "-------------------------------------------------\n";
  vibor();
}

void FloorScales::vi(ostream& stream, int l) {
  stream << persName << " ";
  stream << endl;
  for (int i = 0; i < nabl.size(); i++) {
    stream << pers[l].nabl[i].persDataDay << " ";
    stream << pers[l].nabl[i].persDataMes << " ";
    stream << pers[l].nabl[i].persDataYear << " ";
    stream << pers[l].nabl[i].persVes << " ";
    stream << endl;
  }
}
ostream& operator<<(ostream& stream, const SForFile h) {
  for (int i = 0; i < pers.size(); i++) {
    stream << i + 1 << ")";
    pers[i].vi(stream, i);
  }
  return stream;
}


bool DataFromFile(string filename)
{
  SForFile sf;
  ofstream fin(filename.c_str(), ios_base::out | ios_base::binary);

  if (fin.is_open())
  {
    fin << sf;

    fin.close();
    return true;
  }
  return false;
}

bool DataToFile(string filename)
{
  int day = -1, mes = -1, year = -1, ves = -1;
  string sbuf;
  FloorScales bufPers;
  FloorScales bufNabl;
  int i = 0, n = 0;
  bool s = true;
  SForFile sf;
  ifstream fout(filename.c_str());
  if (fout.is_open())
  {
    while (i != 2) {
      getline(fout, sbuf);
      bufPers.SetName(sbuf);
      fout >> day;
      fout >> mes;
      fout >> year;
      fout >> ves;
      if (day < 1 || day > 31) throw std::logic_error("Input error:wrong number!");
    
      if (mes < 1 || mes > 12) throw std::logic_error("Input error:wrong number!");
     
      if (year < 1900 || year > 2020) throw std::logic_error("Input error:wrong number!");
     
      if (ves < 1 || ves > 1000) throw std::logic_error("Input error:wrong number!");
      n = fout.tellg();
      fout.seekg(n + 5, ios_base::beg);
      bufNabl.SetNabl(day, mes, year, ves);
      date.push_back(bufNabl);
      bufPers.SetNABL(date);
      pers.push_back(bufPers);
      date.pop_back();
      i++;
    }
    return true;
  }
  return false;
}
void SaveToFile()
{
  string filename;

  cout << "Введите имя файла:";
  cin >> filename;
  if (DataFromFile(filename))
  {
    system("cls");
    cout << "Сохранение успешно завершено.\n";
  }
  else
  {
    system("cls");
    cout << "Ошибка сохранения в файл.\n";
  }
}
void LoadFromFile()
{
  string filename;
  cout << "Введите имя файла:";
  cin >> filename;
  if (DataToFile(filename)) {
    system("cls");
    cout << "Данные прочитаны.\n";
  }
  else
  {
    system("cls");
    cout << "Ошибка чтения из файла.\n";
  }
  vibor();
}
void FloorScales::LoadFromFileTest(string filename)
{
  DataToFile(filename);
}
void FloorScales::SaveToFileTest(string filename)
{
 
  DataFromFile(filename);
}
void file() {
  cout << "1- сохранить в файл " << endl;
  cout << "2 - вывести из файла начальные данные " << endl;
  int v = -1;
  while (v < 1 || v>2) {
    cin >> v;
  }
  switch (v)
  {
  case 1:
    SaveToFile();
    break;
  case 2:
    LoadFromFile();
    break;
  }
}
void vibor() {
  PrintMenu();
  int v = -1;
  while (v < 1 || v>10 || ((pers.size() < 1) && (v > 1 && v < 9))) {
    cin >> v;
  }
  switch (v) {
  case 1:
    if (pers.size() < 5) {
      AddFloorScales();
    }
    else {
      cout << "Максимальное количество человек = 5 " << endl;
      vibor();
    }
    break;
  case 2:  PrintAll(); break;
  case 3:  AddNabl(); break;
  case 4:  PrintPers(); break;
  case 5:  dateVes(); break;
  case 6:  SredVes(); break;
  case 7:  MinVes(); break;
  case 8:  MaxVes(); break;
  case 9:  file(); break;
  case 10:  exit; break;
  }

}
void PrintMenu()
{
  cout << endl;
  cout << "Выбирите действие" << endl;
  cout << "1 - Добавить человека" << endl;
  cout << "2 - Вывести начальные показания" << endl;
  cout << "3 - добавить наблюдение" << endl;
  cout << "4 - вывести все показания выбранного человека" << endl;
  cout << "5 - узнать вес по дате и имени" << endl;
  cout << "6 - найти средний вес человека в выбранном месяце или за всю историю" << endl;
  cout << "7 - найти минимальный вес человека в выбранном месяце или за всю историю" << endl;
  cout << "8 - найти максимальный вес человека в выбранном месяце или за всю историю" << endl;
  cout << "9 - сохранить в файл или вывести из файла " << endl;
  cout << "10 - Выход" << endl;


  std::cout << "-------------------------------------------------" << std::endl;
}