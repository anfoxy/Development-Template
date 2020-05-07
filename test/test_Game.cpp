#include <gtest/gtest.h>
#include "Game.h"
TEST(GameConstructors, checkingForCorrectness) {

  ASSERT_NO_THROW(Game a(3456););
}
TEST(GameConstructors1, checkingForCorrectness) {
  ASSERT_NO_THROW(Game a(-3456););
}
TEST(FloorScales1, canFindMinByData) {
  Game a(3456);
  bool k;
  char ours[] = { '4','6','5' };
  k = a.SameDigits(ours, 3);
  EXPECT_EQ(k, false);
}
TEST(FloorScales2, canFindMinByData) {
  Game a(3456);
  bool k;
  char ours[] = { '4','4','5' };
  k = a.SameDigits(ours, 3);
  EXPECT_EQ(k,true);
}
TEST(FloorScales3, canFindMinByData) {
  Game a(3456);
  bool k;
  char ours[] = { '4','4','5' };
  int nou = 345;
  a.Move2Array(nou, ours, 3);
  EXPECT_EQ(k, true);
}
