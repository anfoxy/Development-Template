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


class FloorScales {
public:
  FloorScales() {}
  ~FloorScales() {}

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
    kolnabl = 1;
  }
  void Print();
  void PrintName();
  void PrintNabl();
  void PrintNabl2(int n);
  void addnablpers();
  void Mes();
  void Poisk();
  void sredmes();
  void sredv();
  void minmes();
  void minv();
  void maxmes();
  void maxv();

private:
  vector <FloorScales> nabl;
  string persName;
  int persDataDay;
  int persDataMes;
  int persDataYear;
  int kolnabl;
  int persVes;

  static int cmpfield;
};
void PrintMenu();
void AddFloorScales();
void PrintAll();
void vibor();
#endif  // INCLUDE_FloorScales_H_
