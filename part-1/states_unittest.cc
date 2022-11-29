// Kevin Wortman
// CPSC 120-01
// 2022-11-12
// kwortman@fullerton.edu
// @kevinwortman
//
// Lab 11-01
// Partners:
//
// Object-oriented State class.
//

/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>

#include "states.h"

TEST(StateTest, ReadCSV) {
  std::vector<std::vector<std::string>> csv{ReadCSV("state_demographics.csv", 48)};
  ASSERT_FALSE(csv.empty());
  ASSERT_EQ(52, csv.size());

  ASSERT_EQ(48, csv.at(0).size());
  EXPECT_EQ("State", csv.at(0).at(0));
  EXPECT_EQ("Miscellaneous.Land Area", csv.at(0).at(47));

  ASSERT_EQ(48, csv.at(1).size());
  EXPECT_EQ("Connecticut", csv.at(1).at(0));
  EXPECT_EQ("4842.36", csv.at(1).at(47));

  ASSERT_EQ(48, csv.at(51).size());
  EXPECT_EQ("Wyoming", csv.at(51).at(0));
  EXPECT_EQ("97093.14", csv.at(51).at(47));
}

TEST(StateTest, ConstructorAndName) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_EQ("California", california.Name());
  EXPECT_EQ("Vermont", vermont.Name());
}

TEST(StateTest, ConstructorAndPopulation) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_EQ(39538223, california.Population());
  EXPECT_EQ(643077, vermont.Population());
}

TEST(StateTest, ConstructorAndLandArea) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_DOUBLE_EQ(155779.22, california.LandArea());
  EXPECT_DOUBLE_EQ(9216.66, vermont.LandArea());
}

TEST(StateTest, DefaultConstructor) {
  State def;
  EXPECT_EQ("", def.Name());
  EXPECT_EQ(0, def.Population());
  EXPECT_DOUBLE_EQ(0.0, def.LandArea());
}

TEST(StateTest, PopulationDensity) {
  State california{"California", 39538223, 155779.22};
  State vermont{"Vermont", 643077, 9216.66};
  EXPECT_NEAR(253.809, california.PopulationDensity(), .1);
  EXPECT_NEAR(69.773, vermont.PopulationDensity(), .1);
}

TEST(StateTest, ReadStatesFailure) {
  std::vector<State> states{ReadStates("NONEXISTENT.csv")};
  EXPECT_TRUE(states.empty());
}

TEST(StateTest, ReadStatesSuccess) {
  std::vector<State> states{ReadStates("state_demographics.csv")};
  ASSERT_FALSE(states.empty());
  ASSERT_EQ(51, states.size());

  EXPECT_EQ("Connecticut", states.at(0).Name());
  EXPECT_EQ(3605944, states.at(0).Population());
  EXPECT_DOUBLE_EQ(4842.36, states.at(0).LandArea());

  EXPECT_EQ("California", states.at(10).Name());
  EXPECT_EQ(39538223, states.at(10).Population());
  EXPECT_DOUBLE_EQ(155779.22, states.at(10).LandArea());

  EXPECT_EQ("Indiana", states.at(20).Name());
  EXPECT_EQ(6785528, states.at(20).Population());
  EXPECT_DOUBLE_EQ(35826.11, states.at(20).LandArea());

  EXPECT_EQ("Tennessee", states.at(30).Name());
  EXPECT_EQ(6910840, states.at(30).Population());
  EXPECT_DOUBLE_EQ(41234.9, states.at(30).LandArea());

  EXPECT_EQ("South Carolina", states.at(40).Name());
  EXPECT_EQ(5118425, states.at(40).Population());
  EXPECT_DOUBLE_EQ(30060.7, states.at(40).LandArea());

  EXPECT_EQ("Wyoming", states.at(50).Name());
  EXPECT_EQ(576851, states.at(50).Population());
  EXPECT_DOUBLE_EQ(97093.14, states.at(50).LandArea());

}
