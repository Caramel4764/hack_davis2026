#include <gtest/gtest.h>

#include "Probability.cc"

TEST(Probability, BinomialCoefficient) {
  EXPECT_EQ(Probability::BinomialCoefficient(7, 3), 35);
  EXPECT_EQ(Probability::BinomialCoefficient(20, 7), 77520);
  EXPECT_EQ(Probability::BinomialCoefficient(50, 20), 47129212243960);
  
  // 70c50 = 161884603662657876, but double rounding causes it to be off by ~20
  EXPECT_EQ(Probability::BinomialCoefficient(70, 50) / 100, 1618846036626578);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}