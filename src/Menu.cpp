#include "Menu.h"
ostream& operator<<(ostream& stream, const Menu &d);
Menu::Menu(vector <string> naz, int k, int x, int y, int d) {
  
  if (x < 0 || y < 0) throw std::logic_error("Input error: coordinates cannot be a negative value!");
  if (d < 80) throw std::logic_error("Input error: menu length cannot be less 1!"); // тут вообще вряд ли 1, потому что какое-то минимальное возможное для работы меню значение должно быть, чтобы там хоть что-то было, над этим нужно подумать тебе
  if (k < 0 || k > naz.size()) throw std::logic_error("Input error: count of menu positions cannot be a negative value!");
  kol = k;
  for (int i = 0; i < kol; i++) nazvan.insert(nazvan.end(), naz.at(i));
  Cor.xCor = x;
  Cor.yCor = y;
  Cor.size = d;
  kol = k;
  for (int i = 0; i < kol; i++) nazvan.insert(nazvan.end(), naz.at(i));
  Cor.xCor = x;
  Cor.yCor = y;
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
    str >> Cor.size;
    cout << "\n";
    str >> kol;
    for (int i = 0; i < kol; i++) {
      nazvan.push_back("");
      str >> nazvan.at(i);
    }
    if (Cor.xCor < 0 || Cor.yCor < 0) throw std::logic_error("Input error: coordinates cannot be a negative value!");
    if (Cor.size < 80) throw std::logic_error("Input error: menu length cannot be less 80!"); // тут вообще вряд ли 1, потому что какое-то минимальное возможное для работы меню значение должно быть, чтобы там хоть что-то было, над этим нужно подумать тебе
    if (kol < 0 || kol >nazvan.size()) throw std::logic_error("Input error: count of menu positions cannot be a negative value!");
    str.close();
  }
}
void doSomething(const Menu &d, int n) {
  cout << "вы выбрали ";
  cout << d.nazvan[n - 1] << endl;
  _getch();
}
void delet1(const Menu &d) {
  system("cls");
}
int punktmenu(const Menu &d) {
  int counter = 1, chosen_option = counter;
  int nom = 0;

  while (chosen_option != 2)
  {
    system("cls");
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
ostream& operator<<(ostream& stream, const Menu &d) {
  for (int i = 0; i < d.kol; i++) {
    stream << d.nazvan[i];
    stream << endl;
  }
  HWND hwnd = GetConsoleWindow();
  RECT rect = { d.Cor.xCor,d.Cor.yCor,d.Cor.size, d.Cor.size };
  MoveWindow(hwnd, rect.top, rect.left, rect.bottom - rect.top, rect.right - rect.left, TRUE);
  punktmenu(d);
  delet1(d);
  return stream;
}
