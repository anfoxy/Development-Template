#include <gtest/gtest.h>
#include "FloorScales.h"

TEST(FloorScalesConstructors, checkingForCorrectness) {
 
  ASSERT_NO_THROW(Nabludenie a(4, 5, 2020, 45));
}
TEST(FloorScalesConstructors1, whenTheDayIsSetIncorrectly) {
  ASSERT_ANY_THROW(Nabludenie a(-4, 5, 2020, 45);
  FloorScales s(a, "Lena1");
  Pers s1(s);
  );
}
TEST(FloorScalesConstructors2, whenTheMesIsSetIncorrectly) {
  ASSERT_ANY_THROW(Nabludenie a(4, -5, 2020, 45);
  FloorScales s(a, "Lena1");
  Pers s1(s);
  );
}
TEST(FloorScalesConstructors3, whenTheYearIsSetIncorrectly) {
  ASSERT_ANY_THROW(Nabludenie a(4, 5, -2020, 45);
  FloorScales s(a, "Lena1");
  Pers s1(s);
  );
}
TEST(FloorScalesConstructors4, whenTheVesIsSetIncorrectly) {
  ASSERT_ANY_THROW(Nabludenie a(4, 5, 2020, -45);
  FloorScales s(a, "Lena1");
  Pers s1(s);
  );
}
TEST(FloorScalesConstructorsFileVvod, checkingForCorrectnessFileVvod) {
  Pers s;
  ASSERT_NO_THROW(s.LoadFromFileTest("u"));
}
TEST(FloorScalesConstructorsFileVivod, checkingForCorrectnessFileVivod) {
  Nabludenie a(4, 5, 2020, 45);
  FloorScales s(a, "Lena1");
  Pers s1;
  ASSERT_NO_THROW(s1.SaveToFileTest("Test.txt"));
}
TEST(FloorScales1, canFindMinByData) {
  Nabludenie a(4, 5, 2020, 45);
  Nabludenie b(4, 5, 2020, 30);
  Nabludenie c(4, 5, 2020, 70);
  vector<Nabludenie> e = { a,b,c };
  FloorScales s1(e, "Lena1");
  Pers s(s1);
  int keyMes = 5; 
  int keyYear =2020 ;
  int trueMin = 30;
  int myMin = s1.minmes(keyMes, keyYear);
  EXPECT_EQ(myMin, trueMin);
}
TEST(FloorScales2, canFindMin) {
  Nabludenie a(4, 5, 2020, 45);
  Nabludenie b(4, 5, 2020, 30);
  Nabludenie c(4, 5, 2020, 70);
  vector<Nabludenie> e = { a,b,c };
  FloorScales s1(e, "Lena1");
  Pers s(s1);
  int trueMin = 30;
  int myMin = s1.minv();
  EXPECT_EQ(myMin, trueMin);
}
TEST(FloorScales3, canFindsredByData) {
  Nabludenie a(4, 5, 2020, 45);
  Nabludenie b(4, 5, 2020, 30);
  Nabludenie c(4, 5, 2020, 70);
  vector<Nabludenie> e = { a,b,c };
  FloorScales s1(e, "Lena1");
  Pers s(s1);
  int keyMes = 5;
  int keyYear = 2020;
  int trueMin = 48;
  int myMin = s1.sredmes(keyMes, keyYear);
  EXPECT_EQ(myMin, trueMin);
}
TEST(FloorScales4, canFindsred) {
  Nabludenie a(4, 5, 2020, 45);
  Nabludenie b(4, 5, 2020, 30);
  Nabludenie c(4, 5, 2020, 70);
  vector<Nabludenie> e = { a,b,c };
  FloorScales s1(e, "Lena1");
  Pers s(s1);
  
  int trueMin = 48;
  int myMin = s1.sredv();
  EXPECT_EQ(myMin, trueMin);
}
TEST(FloorScales5, canFindMaxByData) {
  Nabludenie a(4, 5, 2020, 45);
  Nabludenie b(4, 5, 2020, 30);
  Nabludenie c(4, 5, 2020, 70);
  vector<Nabludenie> e = { a,b,c };
  FloorScales s1(e, "Lena1");
  Pers s(s1);
  int keyMes = 5;
  int keyYear = 2020;
  int trueMin = 70;
  int myMin = s1.maxmes1(keyMes, keyYear);
  EXPECT_EQ(myMin, trueMin);
}
TEST(FloorScales6, canFindMax) {
  Nabludenie a(4, 5, 2020, 45);
  Nabludenie b(4, 5, 2020, 30);
  Nabludenie c(4, 5, 2020, 70);
  vector<Nabludenie> e = { a,b,c };
  FloorScales s1(e, "Lena1");
  Pers s(s1);
  int trueMin = 70;
  int myMin = s1.maxv();
  EXPECT_EQ(myMin, trueMin);
}
