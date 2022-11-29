
# Object-Oriented Hi-Lo Game

This exercise revisits the Hi-Lo game from previous labs. Recall that the Hi-Lo game gives a player
a  limited number of tries to guess a secret number. If they guess correctly, they win and the game
ends. If they guess incorrectly, they are given a hint about whether they guessed too high or low,
and the game continues.

Like `part-1`, your assignment is to finish the definition of a class. The `GameState` class defines
the current state of the game. This includes the secret number, and count of how many guesses remain.
You are given a `main.cc` source file with a program that uses the `GameState` class.

This program is divided into several files:
1. `hilo.h` is a header file that declares the `GameState` class and `RandomSecretNumber` function. **Do not change this file.**
1. `hilo.cc` is a source file that defines the functions declared in `hilo.h`. Your work is to add working function bodies to this file (and a header comment).
1. `rng.h` is a header file that declares functions and a class for generating random numbers. Your lecture may or may have not covered how to use this code. You *may* use the `rng.h` code, but *do not have to.*  **Do not change this file.**
1. `rng.cc` is a source file that defines the functions declared in `rng.h`. **Do not change this file.**
1. `main.cc` defines a `main` function that uses the `GameState` class. **Do not change this file.**
1. `hilo_unittest.cc` defines unit tests for the functions of `states.h`.  **Do not change this file.**


The program is intended to:
1. Check for a command-line argument. If a command-line argument exists, use it as the secret number; otherwise generate a random secret number using the `RandomSecretNumber` function from `hilo.h`.
1. Create a `GameState` object to keep track of the game.
1. Loop until the game ends:
   1. Print out the number of guesses remaining based on the `GameState::GuessesLeft` function.
   1. Prompt the user for a guess between 1 and 10.
   1. Decrement the guess count with the `GameState::CountGuess` function.
   1. Use the `GameState::GuessCorrect`, `GameState::GuessTooBig`, and `GameState::GuessTooSmall` functions to determine whether the game is over, or what kind of hint to give.
1. Print out a message about whether the player won or lost.

The `main` function in `main.cc` is provided, and implements this algorithm:

```C++
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
```

## Example Input and Output

Specifying secret number 5, and winning:
```
$ ./hilo 5
You have 4 guesses left.
Enter a guess 1-10: 8
Too big!
You have 3 guesses left.
Enter a guess 1-10: 2
Too small!
You have 2 guesses left.
Enter a guess 1-10: 5
You won!
```

Specifying secret number 9, and losing:
```
$ ./hilo 9
You have 4 guesses left.
Enter a guess 1-10: 1
Too small!
You have 3 guesses left.
Enter a guess 1-10: 2
Too small!
You have 2 guesses left.
Enter a guess 1-10: 3
Too small!
You have 1 guesses left.
Enter a guess 1-10: 4
Too small!
You lost!
```

Specifying secret number 2, and losing:
```
$ ./hilo 9
You have 4 guesses left.
Enter a guess 1-10: 9
Too big!
You have 3 guesses left.
Enter a guess 1-10: 8
Too big!
You have 2 guesses left.
Enter a guess 1-10: 7
Too big!
You have 1 guesses left.
Enter a guess 1-10: 6
Too big!
You lost!
```

Using a random secret number (by giving no arguments), and winning:
```
$ ./hilo
You have 4 guesses left.
Enter a guess 1-10: 5
Too big!
You have 3 guesses left.
Enter a guess 1-10: 3
Too big!
You have 2 guesses left.
Enter a guess 1-10: 2
Too big!
You have 1 guesses left.
Enter a guess 1-10: 1
You won!
```


## Test Cases

This program does not have manual test cases. Instead, test your function definitions with `$ make unittest` and test your entire program behavior with `$ make test`.

## What to Do

1. With your partner, edit the `hilo.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code.
1. Compile your program with the `$ make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `$ ./hilo` shell command.
1. Test that your program passes all unit tests with the `$ make unittest` command. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Test your program against automated test with the `$ make test` command. Debug any runtime errors or logic errors using the same procedures.
1. Check your header with the `$ make header` shell command. Correct any errors.
1. Check for format errors with the `$ make format` shell command. Correct any errors.
1. Check for lint errors with the `$ make lint` shell command. Correct any errors.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

## Next Steps

After you have pushed your code, you are done with this lab. You may ask your TA for permission to sign out and leave.
