#include <gtest/gtest.h>
#include "Decima.h"

TEST(Addition, CanAddTwoPositiveNumbers) {
  Decima a = "222333444";
  Decima b = "666777";
  Decima p = "223000221";
  Decima c = a + b;
  EXPECT_EQ(c,p);
}
TEST(raznost, CanDiffTwoPositiveNumbers) {
  Decima a = "200000";
  Decima b = "100000";
  Decima p = "100000";
  Decima c = a - b;
  EXPECT_EQ(c, p);
}
TEST(sravnenie, CanSravnTwoPositiveNumbers) {
  Decima a = "234567";
  Decima b = "234567";
  Decima p1 = "1";
  if (a == b) {
   Decima p2 = "1";
    EXPECT_EQ(p1, p2);
  } else { 
   Decima p2 = "0"; 
  EXPECT_EQ(p1, p2);
  }
}
TEST(priravniaem, CanpriravnivaemTwoPositiveNumbers) {
  Decima a = "200000";
  Decima b = "100000";
  a = b;
  EXPECT_EQ(a, b);
}
TEST(kop, CanCopTwoPositiveNumbers) {
  Decima a = "200000";
  Decima b(a);
  EXPECT_EQ(a, b);
}