#include "Menu.h"
ostream& operator<<(ostream& stream, const Menu &d);
Menu::Menu(vector <string> naz, int k, int x, int y, int d) {
  
 
  kol = k;
  if (kol < 0 || kol >naz.size()) throw std::logic_error("Input error: count of menu positions cannot be a negative value!");
  for (int i = 0; i < kol; i++) nazvan.insert(nazvan.end(), naz.at(i));
  if (x < 0 || y < 0) throw std::logic_error("Input error: coordinates cannot be a negative value!");
  Cor.xCor = x;
  Cor.yCor = y;
  if (d < 80) throw std::logic_error("Input error: menu length cannot be less 80!");
  Cor.size = d;
  
}
Menu::Menu(string n) {
  ifstream str(n);
  if (!str.is_open()) // если файл не открыт
    cout << "Файл не может быть открыт!\n"; // сообщить об этом
  else
  {

    str >> Cor.xCor;
    str >> Cor.yCor;
    if (Cor.xCor < 0 || Cor.yCor < 0) throw std::logic_error("Input error: coordinates cannot be a negative value!");
    str >> Cor.size;
    cout << "\n";
    if (Cor.size < 80) throw std::logic_error("Input error: menu length cannot be less 80!");
    str >> kol;
    if (kol < 0) throw std::logic_error("Input error: count of menu positions cannot be a negative value!");
    for (int i = 0; i < kol; i++) {
      nazvan.push_back("");
      str >> nazvan.at(i);
    }
    str.close();
  }
}
ostream& operator<<(ostream& stream, const Menu &d) {
  for (int i = 0; i < d.kol; i++) {
    stream << d.nazvan[i];
    stream << endl;
  }
  stream << d.Cor.xCor;
  stream << endl;
  stream << d.Cor.yCor;
  stream << endl;
  stream << d.Cor.size;
  return stream;
}
void razm(const Menu &c) {
  vector <string> n1;
  for (int i = 0; i < c.kol; i++) {
   n1.push_back(" ");
   n1.at(i) = c.nazvan[i];
  }
  cout << "введите х  ";
  int x;
  cin >> x;
  cout << "введите y  ";
  int y;
  cin >> y;
  cout << "введите d  ";
  int d;
  cin >> d;
  Menu b(n1, 3, x, y, d);
  punktmenu(b);
}

void doSomething(const Menu &d, int n) {
  cout << "Загрузка...";
  Sleep(3000);
  system("cls");
  cout << "вы выбрали ";
  HWND hwnd = GetConsoleWindow();
  cout << d.nazvan[n - 1] << endl;
  switch (n) {
  case 1:
    razm(d);
    break;
  case 2:
    ShowWindow(hwnd,SW_MINIMIZE);
    punktmenu(d);
    break;
  case 3:
    exit(0);
    break;
  default:
    Sleep(3000);
    exit(0);
  }
  _getch();
}

int punktmenu(const Menu &d) {
  cout << "Создание меню...";
  Sleep(3000);
  HWND hwnd = GetConsoleWindow();
  RECT rect = { d.Cor.xCor,d.Cor.yCor,d.Cor.size, d.Cor.size };
  MoveWindow(hwnd, rect.top, rect.left, rect.bottom - rect.top, rect.right - rect.left, TRUE);
  
  int counter = 1, chosen_option = counter;
  int nom = 0;
  while (chosen_option != 2)
  {
    system("cls");
    cout << "Выберете пункт с помощью кнопок 'w' и 's' " << endl;
    for (size_t i = 0; i < d.kol; ++i)
    {
      if ((i + 1) == counter) {
        nom = i + 1;
        cout << "> " << d.nazvan[i] << endl;
      }
      else {
        cout << d.nazvan[i] << endl;
      }
    }
    char pressed = _getch();

    if (pressed == 'w' && counter != 1)
      counter--;
    if (pressed == 's' && counter != d.kol)
      counter++;

    if (pressed == '\r' || pressed == '\n') {
      chosen_option = counter;
      system("cls");
      doSomething(d, nom);
      return 0;
      _getch();
    }
  }
}
