// Kevin Wortman
// CPSC 120-01
// 2022-11-12
// kwortman@fullerton.edu
// @kevinwortman
//
// Lab 11-02
// Partners:
//
// Object-oriented hilo game.
//

/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>

#include "hilo.h"

TEST(GameStateTest, ConstructorAndSecret) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};
  EXPECT_EQ(1, g1.Secret());
  EXPECT_EQ(5, g5.Secret());
  EXPECT_EQ(10, g10.Secret());
}

TEST(GameStateTest, GuessesLeft) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};
  EXPECT_EQ(4, g1.GuessesLeft());
  EXPECT_EQ(4, g5.GuessesLeft());
  EXPECT_EQ(4, g10.GuessesLeft());
}

TEST(GameStateTest, GuessCorrect) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};

  EXPECT_TRUE(g1.GuessCorrect(1));
  EXPECT_FALSE(g1.GuessCorrect(2));
  EXPECT_FALSE(g1.GuessCorrect(3));
  EXPECT_FALSE(g1.GuessCorrect(4));
  EXPECT_FALSE(g1.GuessCorrect(5));
  EXPECT_FALSE(g1.GuessCorrect(6));
  EXPECT_FALSE(g1.GuessCorrect(7));
  EXPECT_FALSE(g1.GuessCorrect(8));
  EXPECT_FALSE(g1.GuessCorrect(9));
  EXPECT_FALSE(g1.GuessCorrect(10));

  EXPECT_FALSE(g5.GuessCorrect(1));
  EXPECT_FALSE(g5.GuessCorrect(2));
  EXPECT_FALSE(g5.GuessCorrect(3));
  EXPECT_FALSE(g5.GuessCorrect(4));
  EXPECT_TRUE(g5.GuessCorrect(5));
  EXPECT_FALSE(g5.GuessCorrect(6));
  EXPECT_FALSE(g5.GuessCorrect(7));
  EXPECT_FALSE(g5.GuessCorrect(8));
  EXPECT_FALSE(g5.GuessCorrect(9));
  EXPECT_FALSE(g5.GuessCorrect(10));

  EXPECT_FALSE(g10.GuessCorrect(1));
  EXPECT_FALSE(g10.GuessCorrect(2));
  EXPECT_FALSE(g10.GuessCorrect(3));
  EXPECT_FALSE(g10.GuessCorrect(4));
  EXPECT_FALSE(g10.GuessCorrect(5));
  EXPECT_FALSE(g10.GuessCorrect(6));
  EXPECT_FALSE(g10.GuessCorrect(7));
  EXPECT_FALSE(g10.GuessCorrect(8));
  EXPECT_FALSE(g10.GuessCorrect(9));
  EXPECT_TRUE(g10.GuessCorrect(10));
}

TEST(GameStateTest, GuessTooBig) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};

  EXPECT_FALSE(g1.GuessTooBig(1));
  EXPECT_TRUE(g1.GuessTooBig(2));
  EXPECT_TRUE(g1.GuessTooBig(3));
  EXPECT_TRUE(g1.GuessTooBig(4));
  EXPECT_TRUE(g1.GuessTooBig(5));
  EXPECT_TRUE(g1.GuessTooBig(6));
  EXPECT_TRUE(g1.GuessTooBig(7));
  EXPECT_TRUE(g1.GuessTooBig(8));
  EXPECT_TRUE(g1.GuessTooBig(9));
  EXPECT_TRUE(g1.GuessTooBig(10));

  EXPECT_FALSE(g5.GuessTooBig(1));
  EXPECT_FALSE(g5.GuessTooBig(2));
  EXPECT_FALSE(g5.GuessTooBig(3));
  EXPECT_FALSE(g5.GuessTooBig(4));
  EXPECT_FALSE(g5.GuessTooBig(5));
  EXPECT_TRUE(g5.GuessTooBig(6));
  EXPECT_TRUE(g5.GuessTooBig(7));
  EXPECT_TRUE(g5.GuessTooBig(8));
  EXPECT_TRUE(g5.GuessTooBig(9));
  EXPECT_TRUE(g5.GuessTooBig(10));

  EXPECT_FALSE(g10.GuessTooBig(1));
  EXPECT_FALSE(g10.GuessTooBig(2));
  EXPECT_FALSE(g10.GuessTooBig(3));
  EXPECT_FALSE(g10.GuessTooBig(4));
  EXPECT_FALSE(g10.GuessTooBig(5));
  EXPECT_FALSE(g10.GuessTooBig(6));
  EXPECT_FALSE(g10.GuessTooBig(7));
  EXPECT_FALSE(g10.GuessTooBig(8));
  EXPECT_FALSE(g10.GuessTooBig(9));
  EXPECT_FALSE(g10.GuessTooBig(10));
}

TEST(GameStateTest, GuessTooSmall) {
  GameState g1{1};
  GameState g5{5};
  GameState g10{10};

  EXPECT_FALSE(g1.GuessTooSmall(1));
  EXPECT_FALSE(g1.GuessTooSmall(2));
  EXPECT_FALSE(g1.GuessTooSmall(3));
  EXPECT_FALSE(g1.GuessTooSmall(4));
  EXPECT_FALSE(g1.GuessTooSmall(5));
  EXPECT_FALSE(g1.GuessTooSmall(6));
  EXPECT_FALSE(g1.GuessTooSmall(7));
  EXPECT_FALSE(g1.GuessTooSmall(8));
  EXPECT_FALSE(g1.GuessTooSmall(9));
  EXPECT_FALSE(g1.GuessTooSmall(10));

  EXPECT_TRUE(g5.GuessTooSmall(1));
  EXPECT_TRUE(g5.GuessTooSmall(2));
  EXPECT_TRUE(g5.GuessTooSmall(3));
  EXPECT_TRUE(g5.GuessTooSmall(4));
  EXPECT_FALSE(g5.GuessTooSmall(5));
  EXPECT_FALSE(g5.GuessTooSmall(6));
  EXPECT_FALSE(g5.GuessTooSmall(7));
  EXPECT_FALSE(g5.GuessTooSmall(8));
  EXPECT_FALSE(g5.GuessTooSmall(9));
  EXPECT_FALSE(g5.GuessTooSmall(10));

  EXPECT_TRUE(g10.GuessTooSmall(1));
  EXPECT_TRUE(g10.GuessTooSmall(2));
  EXPECT_TRUE(g10.GuessTooSmall(3));
  EXPECT_TRUE(g10.GuessTooSmall(4));
  EXPECT_TRUE(g10.GuessTooSmall(5));
  EXPECT_TRUE(g10.GuessTooSmall(6));
  EXPECT_TRUE(g10.GuessTooSmall(7));
  EXPECT_TRUE(g10.GuessTooSmall(8));
  EXPECT_TRUE(g10.GuessTooSmall(9));
  EXPECT_FALSE(g10.GuessTooSmall(10));
}

TEST(GameStateTest, CountGuess) {
  GameState g1{1};
  ASSERT_EQ(4, g1.GuessesLeft());

  g1.CountGuess();
  EXPECT_EQ(3, g1.GuessesLeft());

  g1.CountGuess();
  EXPECT_EQ(2, g1.GuessesLeft());

  g1.CountGuess();
  EXPECT_EQ(1, g1.GuessesLeft());

  g1.CountGuess();
  EXPECT_EQ(0, g1.GuessesLeft());
}

TEST(GameStateTest, GameOver) {
  GameState g1{1}; // 4 left
  EXPECT_FALSE(g1.GameOver());
  g1.CountGuess(); // 3 left
  EXPECT_FALSE(g1.GameOver());
  g1.CountGuess(); // 2 left
  EXPECT_FALSE(g1.GameOver());
  g1.CountGuess(); // 1 left
  EXPECT_FALSE(g1.GameOver());
  g1.CountGuess(); // 0 left
  EXPECT_TRUE(g1.GameOver());
}