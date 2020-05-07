#include <gtest/gtest.h>
#include "Credit.h"
#include "ProcCenter.h"

TEST(Credit, checkingForCorrectness) {
  ASSERT_NO_THROW(inf s1("Nastya", "Kazhaeva", "Vladimirovna", "1234", 10000););
}
TEST(Credit1, whenTheMoneyIsSetIncorrectly) {
  ASSERT_ANY_THROW(inf s1("Nastya", "Kazhaeva", "Vladimirovna", "1234", -10000);
  );
}
TEST(Credit2, RasschetViplat) {
  int sum = 1000;
  int srok = 1;
  int proc = 16;
  int res;
  res=raschetC( sum, srok, proc);
  int res1 = 90;
  EXPECT_EQ(res, res1);
}
TEST(Credit2_1, RasschetViplat) {
  int sum = 3000000;
  int srok = 15;
  int proc = 8;
  int res;
  res = raschetC(sum, srok, proc);
  int res1 = 28669;
  EXPECT_EQ(res, res1);
}
TEST(Credit2_2, RasschetViplat) {
  int sum = 40000;
  int srok = 15;
  int proc = 13;
  int res;
  res = raschetC(sum, srok, proc);
  int res1 = 506;
  EXPECT_EQ(res, res1);
}
TEST(Credit3, OdobrenieViplat) {
  inf s1("Nastya", "Kazhaeva", "Vladimirovna", "1234", 10000);
  ProcCenter h(s1);
  Credit n;
  int sum = 1000;
  int srok = 1;
  int proc = 16;
  int res;
  res = raschetC(sum, srok, proc);
  int odob;
  odob = n.proverka(h, res);
  EXPECT_EQ(odob, 1);
}
TEST(Credit4, OdobrenieViplat) {
  inf s1("Nastya", "Kazhaeva", "Vladimirovna", "1234", 10000);
  ProcCenter h(s1);
  Credit n;
  int sum = 1000000;
  int srok = 1;
  int proc = 16;
  int res;
  res = raschetC(sum, srok, proc);
  int odob;
  odob = n.proverka(h, res);
  EXPECT_EQ(odob, -1);
}