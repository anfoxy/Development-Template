#include <gtest/gtest.h>
#include "FloorScales.h"

TEST(FloorScalesConstructors0, CanAddTwoPositiveNumbers) {
  ASSERT_NO_THROW(FloorScales s("Nikita", 4, 5, 2020, 45));
}
TEST(FloorScalesConstructors, CantCreateMenuWithInitConstractorIfCoordinatesIsNegative) {

  ASSERT_ANY_THROW(FloorScales s("Nikita", -4, 5, 2020, 45));
}
TEST(FloorScalesConstructors1, CantCreateMenuWithInitConstractorIfCoordinatesIsNegative) {
 
  ASSERT_ANY_THROW(FloorScales s("Nikita", 4, -5, 2020, 45));
}
TEST(FloorScalesConstructors2, CantCreateMenuWithInitConstractorIfNumbeêOfMenuItemsIsNegative) {
 
  ASSERT_ANY_THROW(FloorScales s("Nikita", 4, 5, -2020, 45));
}
TEST(FloorScalesConstructors3, CantCreateMenuWithInitConstractorIfMenuLengthNegative) {
 
  ASSERT_ANY_THROW(FloorScales s("Nikita", 4, 5, 2020, -45));
}
TEST(FloorScalesConstructors5, CanAddTwoPositiveNumbers) {
  FloorScales s;
  ASSERT_NO_THROW(s.LoadFromFileTest());
}
TEST(FloorScalesConstructors6, CanAddTwoPositiveNumbers) {
  FloorScales s("Nikita", 4, 5, 2020, 45);
  ASSERT_NO_THROW(s.SaveToFileTest());
}
