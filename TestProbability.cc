#include <gtest/gtest.h>

#include "Probability.cc"
#include "Test.h"

// Check functionality of Test struct
TEST(Probability, CreateTest) {
  // Manual TestInfo creation
  TestInfo manual_test = Probability::CreateTest(1, 6, 7);
  EXPECT_EQ(manual_test.num_correct, 1);
  EXPECT_EQ(manual_test.num_options, 6);
  EXPECT_EQ(manual_test.num_questions, 7);
  EXPECT_EQ(manual_test.CorrectChance(), 1.0/6.0);
  EXPECT_EQ(manual_test.IncorrectChance(), 5.0/6.0);

  // CreateTest() TestInfo creation
  TestInfo function_test = Probability::CreateTest(1, 6, 7);
  EXPECT_EQ(function_test.num_correct, 1);
  EXPECT_EQ(function_test.num_options, 6);
  EXPECT_EQ(function_test.num_questions, 7);
  EXPECT_EQ(function_test.CorrectChance(), 1.0/6.0);
  EXPECT_EQ(function_test.IncorrectChance(), 5.0/6.0);
}

TEST(Probability, BinomialCoefficient) {
  EXPECT_EQ(Probability::BinomialCoefficient(7, 3), 35);
  EXPECT_EQ(Probability::BinomialCoefficient(20, 7), 77520);
  EXPECT_EQ(Probability::BinomialCoefficient(50, 20), 47129212243960);

  // 70c50 = 161884603662657876, but double rounding causes it to be off by ~20
  EXPECT_EQ(Probability::BinomialCoefficient(70, 50) / 100, 1618846036626578);
}

TEST(Probability, OneAnswerTestResults) {
  // TestInfo test = Probability::CreateTest(1, 6, 7);
}

TEST(Probability, OneAnswerCutoffProbability) {
  EXPECT_EQ(true, true);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
