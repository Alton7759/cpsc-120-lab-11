// Wilfredo Rodas
// CPSC 120-01
// 2022-11-28
// rodaswilfredo24@csu.fullerton.edu
// @rodasw24
//
// Lab 11-02
// Partners: @AHan003, @alton7759
//
// Object-oriented State class.
//
#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret)

    : secret_(secret), guesses_left_(4) {}

int GameState::Secret() const { return secret_; }

int GameState::GuessesLeft() const { return guesses_left_; }

bool GameState::GuessCorrect(int guess) const { return guess == secret_; }

bool GameState::GuessTooBig(int guess) const { return guess > secret_; }

bool GameState::GuessTooSmall(int guess) const { return guess < secret_; }

void GameState::CountGuess() { guesses_left_ = guesses_left_ - 1; }

bool GameState::GameOver() const { return guesses_left_ == 0; }

int RandomSecretNumber() {
  double minimum_random_number = 1.0;
  double maximum_random_number = 10.0;
  RandomNumberGenerator my_random_number_generator{minimum_random_number,
                                                   maximum_random_number};
  int random_number = int(my_random_number_generator.next());
  return random_number;
}
