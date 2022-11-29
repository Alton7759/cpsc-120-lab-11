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

#include <iostream>
#include <random>
#include <string>

#include "hilo.h"

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);

  int secret{0};
  if (arguments.size() == 2) {
    secret = std::stoi(arguments.at(1));
  } else {
    secret = RandomSecretNumber();
  }

  GameState game{secret};
  bool won{false};
  while (!game.GameOver()) {
    std::cout << "You have " << game.GuessesLeft() << " guesses left.\n";

    int guess{0};
    do {
      std::cout << "Enter a guess 1-10: ";
      std::cin.clear();
      std::cin >> guess;
    } while (!std::cin || (guess < 1) || (guess > 10));

    game.CountGuess();

    if (game.GuessCorrect(guess)) {
      won = true;
      break;
    }
    if (game.GuessTooBig(guess)) {
      std::cout << "Too big!\n";
    }
    if (game.GuessTooSmall(guess)) {
      std::cout << "Too small!\n";
    }
  }

  if (won) {
    std::cout << "You won!\n";
  } else {
    std::cout << "You lost!\n";
  }

  return 0;
}