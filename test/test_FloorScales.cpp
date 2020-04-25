#include <gtest/gtest.h>
#include "FloorScales.h"

TEST(FloorScalesConstructors, checkingForCorrectness) {
  ASSERT_NO_THROW(FloorScales s("Nikita", 4, 5, 2020, 45));
}
TEST(FloorScalesConstructors1, whenTheDayIsSetIncorrectly) {

  ASSERT_ANY_THROW(FloorScales s("Nikita", -4, 5, 2020, 45));
}
TEST(FloorScalesConstructors2, whenTheMesIsSetIncorrectly) {
 
  ASSERT_ANY_THROW(FloorScales s("Nikita", 4, -5, 2020, 45));
}
TEST(FloorScalesConstructors3, whenTheYearIsSetIncorrectly) {
 
  ASSERT_ANY_THROW(FloorScales s("Nikita", 4, 5, -2020, 45));
}
TEST(FloorScalesConstructors4, whenTheVesIsSetIncorrectly) {
 
  ASSERT_ANY_THROW(FloorScales s("Nikita", 4, 5, 2020, -45));
}
TEST(FloorScalesConstructorsFileVvod, checkingForCorrectnessFileVvod) {
  FloorScales s;
  ASSERT_NO_THROW(s.LoadFromFileTest("Test.txt"));
}
TEST(FloorScalesConstructorsFileVivod, checkingForCorrectnessFileVivod) {
  FloorScales s("Nikita", 4, 5, 2020, 45);
  ASSERT_NO_THROW(s.SaveToFileTest("Test.txt"));
}
