#ifndef INCLUDE_FloorScales_H_
#define INCLUDE_FloorScales_H_
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <time.h>
#include <stdlib.h>

using namespace std;


struct SForFile
{
  string Name;
  int Day;
  int Mes;
  int Year;
  int Ves;
};
struct stry
{
  int Day;
  int Mes;
  int Year;
};

class FloorScales {
public:
  FloorScales() {}
  ~FloorScales() {}
  FloorScales(string name, int day, int mes, int year, int ves);
  friend ostream& operator<<(ostream& stream, const SForFile h);//
  string GetName() { return persName; }
  int Getday() { return persDataDay; }
  int Getmes() { return persDataMes; }
  int Getyear() { return persDataYear; }
  int GetVes() { return persVes; }
  void SetNABL(vector <FloorScales> nabl1) {
    nabl = nabl1;
  }
  void SetName(string name) { persName = name; }
  void SetNabl(int day, int mes, int year, int ves) {
    persDataDay = day;
    persDataMes = mes;
    persDataYear = year;
    persVes = ves;
  }
  void SaveToFileTest(string filename);
  void LoadFromFileTest(string filename);
  void Print();
  void PrintName();
  void PrintNabl();
  void addnablpers();
  void input();
  void vvodkeyDate();
  void Mes();
  void Poisk();
  int sredmes(int keyMes, int keyYear);
  void sred_with_output(int keyMes, int keyYear);
  void sredmes();
  void vi(ostream & stream, int l);
  void sredv();
  void minmes();
  int minmes(int keyMes, int keyYear);
  void minmes_with_output(int keyMes, int keyYear);
  void minv();
  int maxmes1(int keyMes, int keyYear);
  void max_with_output(int keyMes, int keyYear);
  void maxmes();
  void maxv();
 
private:

  stry stry;
  vector <FloorScales> nabl;
  string persName;
  int persDataDay;
  int persDataMes;
  int persDataYear;
  int persVes;

  static int cmpfield;
};
void PrintMenu();
void AddFloorScales();
void PrintAll();
void vibor();
#endif  // INCLUDE_FloorScales_H_
