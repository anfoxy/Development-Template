#ifndef INCLUDE_Game_H_
#define INCLUDE_Game_H_
#include <iostream>
#include <ctime>
#define MAX 9
using namespace std;
class Game {
private:
  int kol=0;
  int nOurs;       //число, введенное пользователем
  int bools = 0;	 // быки
  int cows = 0;	   // коровы
  char mech[MAX];  //загаданно
  char ours[MAX];  //пользователь
  int raz = 0;
public:
  void SetNom(char* n) {
    for (int i = 0; i < kol; i++) {
      mech[i] = n[i];
    }
  }
  Game(int i);
  Game() { kol = 0; }
  ~Game() {}
  void game1();
  void Move2Array(int value, char ar[], int n);
  bool SameDigits(char ar[], int n);
  void rand_4(char ar[], int n);
};
#endif  // INCLUDE_Game_H_
