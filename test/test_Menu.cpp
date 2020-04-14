#include <gtest/gtest.h>
#include "menu.h"

TEST(MenuConstructors, CanCreateMenuWithInitConstractor) {
  vector <string> str = {"One", "Two", "Three"};
  ASSERT_NO_THROW(Menu new_menu(str, 3, 0, 0, 100));
}

TEST(MenuConstructors1, CantCreateMenuWithInitConstractorIfCoordinatesIsNegative) {
  vector <string> str = { "One", "Two", "Three" };
  ASSERT_ANY_THROW(Menu new_menu(str, 3, -10, 0, 80));
}
TEST(MenuConstructors2, CantCreateMenuWithInitConstractorIfNumbeêOfMenuItemsIsNegative) {
  vector <string> str = { "One", "Two", "Three" };
  ASSERT_ANY_THROW(Menu new_menu(str, -3, 10, 0, 80));
}
TEST(MenuConstructors3, CantCreateMenuWithInitConstractorIfMenuLengthNegative) {
  vector <string> str = { "One", "Two", "Three" };
  ASSERT_ANY_THROW(Menu new_menu(str, 3, 10, 0, -80));
}
TEST(MenuConstructors4, CantCreateMenuWithInitConstractorIfNumbeêOfMenuItemsIsNegative) {
  vector <string> str = { "One", "Two", "Three" };
  ASSERT_ANY_THROW(Menu new_menu(str, 4, 10, 0, 80));
}