#include <gtest/gtest.h>
#include <vector>

#include "Probability.cc"
#include "Test.h"

#include <stdio.h>

bool AboutEquals(double d1, double d2);

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

  // Off by ~20 close to max value of unsigned long long
  EXPECT_TRUE(AboutEquals(Probability::BinomialCoefficient(70, 50), 161884603662657876));
}

TEST(Probability, OneAnswerTestResults) {
  TestInfo test = Probability::CreateTest(1, 6, 7);

  std::vector<double> test_results = Probability::CalculateTestResults(test);

  EXPECT_TRUE(AboutEquals(test_results[0], 0.2790816472));  // Exact Fraction: 78125/279936
  EXPECT_TRUE(AboutEquals(test_results[1], 0.3907143061));  // Exact Fraction: 109375/279936
  EXPECT_TRUE(AboutEquals(test_results[2], 0.2344285837));  // Exact Fraction: 21875/93312
  EXPECT_TRUE(AboutEquals(test_results[3], 0.07814286123));  // Exact Fraction: 21875/279936
  EXPECT_TRUE(AboutEquals(test_results[4], 0.01562857225));  // Exact Fraction: 4375/279936
  EXPECT_TRUE(AboutEquals(test_results[5], 0.001875428669));  // Exact Fraction: 175/93312
  EXPECT_TRUE(AboutEquals(test_results[6], 0.000125028578));  // Exact Fraction: 35/279936
  EXPECT_TRUE(AboutEquals(test_results[7], 0.000003572245085));  // Exact Fraction: 1/279936
}

TEST(Probability, OneAnswerCutoffProbability) {
  TestInfo test = Probability::CreateTest(1, 6, 7);

  std::vector<double> test_results = Probability::CalculateTestResults(test);

  double zero_or_more = Probability::CutoffProbability(0, test_results);
  double one_or_more = Probability::CutoffProbability(1, test_results);
  double two_or_more = Probability::CutoffProbability(2, test_results);
  double three_or_more = Probability::CutoffProbability(3, test_results);
  double four_or_more = Probability::CutoffProbability(4, test_results);
  double five_or_more = Probability::CutoffProbability(5, test_results);
  double six_or_more = Probability::CutoffProbability(6, test_results);
  double seven_or_more = Probability::CutoffProbability(7, test_results);

  EXPECT_TRUE(AboutEquals(zero_or_more, 1));  // Exact Fraction: 1/1
  EXPECT_TRUE(AboutEquals(one_or_more, 0.7209183528));  // Exact Fraction: 201811/279936
  EXPECT_TRUE(AboutEquals(two_or_more, 0.3302040466));  // Exact Fraction: 7703/23328
  EXPECT_TRUE(AboutEquals(three_or_more, 0.09577546296));  // Exact Fraction: 331/3456
  EXPECT_TRUE(AboutEquals(four_or_more, 0.01763260174));  // Exact Fraction: 617/34992
  EXPECT_TRUE(AboutEquals(five_or_more, 0.002004029492));  // Exact Fraction: 187/93312
  EXPECT_TRUE(AboutEquals(six_or_more, 0.000128600823));  // Exact Fraction: 1/7776
  EXPECT_TRUE(AboutEquals(seven_or_more, 0.000003572245085));  // Exact Fraction: 1/279936
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// Used to compare doubles in EXPECT_EQ()
bool AboutEquals(double d1, double d2) {
  return (d1 > d2) ? ((d1 - d2) / d2 < 0.00001) : ((d2 - d1) / d1 < 0.00001);
}