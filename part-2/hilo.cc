// TODO add a header

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
}

int GameState::Secret() const {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
}

int GameState::GuessesLeft() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return 0; // TODO: replace this return statement with one that actually works
}

bool GameState::GuessCorrect(int guess) const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  return false; // TODO: replace this return statement with one that actually works
}

bool GameState::GuessTooBig(int guess) const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  return false; // TODO: replace this return statement with one that actually works
}

bool GameState::GuessTooSmall(int guess) const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Use an if statement.
  return false; // TODO: replace this return statement with one that actually works
}

void GameState::CountGuess() {
  // TODO: write statements to implement this function, and delete this comment
}

bool GameState::GameOver() const {
  // TODO: write statements to implement this function, and delete this comment
  return false; // TODO: replace this return statement with one that actually works
}

int RandomSecretNumber() {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: first seed the random number generator
  // then generate a random number between 1 and 10
  // finally return that random number
  return 0; // TODO: replace this return statement with one that actually works
}
