#include <gtest/gtest.h>
#include "ClassMoney.h"

TEST(Addition, CanAddTwoPositiveNumbers) {
  Money c2(5, 10), c3(6, 10);
  const Money c4(11, 20);
  Money c1_ = c2 + c3;
  EXPECT_EQ(c1_, c4);
}

TEST(Addition, CanAddTwoNumbersDifferentSign) {
  Money c2(5, 10);
  const Money c5(40, 80);
  Money c1_ = c2 * 8;
  EXPECT_EQ(c1_, c5);
}

TEST(Addition, CanAddTwoNegativeNumbers) {
  Money c2(5, 10), c3(6, 10);
  const Money c6(-1, 0);
  Money c1_ = c2 - c3;
  EXPECT_EQ(c1_, c6);
}