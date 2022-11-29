
# State Class

The purpose of this exercise is for you to write code dealing with an object-oriented class.
The given code includes a program in `main.cc` that uses a class called `State`.
The bodies of `State`'s member functions are TODOs. Your task is to fill in the function definitions so
that the program works properly.

As [explained in learncpp.com section 2.11](https://www.learncpp.com/cpp-tutorial/header-files/),
source modules should be divided into two linked files, a `.h` *header file* and `.cc` *source file.*
This lab is following this practice. The `State` class is declared in the header file `states.h`, and
the function definitions go in the source file `states.cc`.

This program is divided into several files:
1. `states.h` is a header file that declares the `State` class.  **Do not change this file.**
1. `states.cc` is a source file that defines the member functions of the `State` class. Your work is to add working function bodies to this file (and a header comment).
1. `main.cc` defines a `main` function that uses the `State` class. **Do not change this file.**
1. `states_unittest.cc` defines unit tests for the functions of `states.h`.  **Do not change this file.**
1. `state_demographics.csv` is a CSV data file used by the program. **Do not change this file.**

The program is intended to:
1. Read from the [State Demographics CSV File](https://corgis-edu.github.io/corgis/csv/state_demographics/).
1. Create a `std::vector` of `State` objects. Each `State` object represents one state of the USA (or the District of Columbia). Each `State` object has data members for the name, population, and land area of the state. The information for each state comes from the CSV data.
1. Loop through the `State`s to find the state with the highest, and lowest, population density. A state's population density is the population divided by the land area.
1. Print out the name and density of the states with the highest and lowest density.

The `main` function in `main.cc` is provided, and implements this algorithm:

```C++
int main(int argc, char* argv[]) {
  std::vector<State> states{ReadStates("state_demographics.csv")};

  State densest{states.front()};
  State sparsest{states.front()};
  for (State& state : states) {
    if (state.PopulationDensity() > densest.PopulationDensity()) {
      densest = state;
    }
    if (state.PopulationDensity() < sparsest.PopulationDensity()) {
      sparsest = state;
    }
  }

  std::cout << "The densest state is " << densest.Name() << " ("
            << densest.PopulationDensity() << ")\n";

  std::cout << "The sparsest state is " << sparsest.Name() << " ("
            << sparsest.PopulationDensity() << ")\n";

  return 0;
}
```

## Example Input and Output

```
$ ./states
The densest state is District of Columbia (11294.8)
The sparsest state is Alaska (1.28521)
```


## Test Cases

This program does not have manual test cases. Instead, test your function definitions with `$ make unittest` and test your entire program behavior with `$ make test`.

## What to Do

1. With your partner, edit the `states.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code.
1. Compile your program with the `$ make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `$ ./judge` shell command.
1. Test that your program passes all unit tests with the `$ make unittest` command. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Test your program against automated test with the `$ make test` command. Debug any runtime errors or logic errors using the same procedures.
1. Check your header with the `$ make header` shell command. Correct any errors.
1. Check for format errors with the `$ make format` shell command. Correct any errors.
1. Check for lint errors with the `$ make lint` shell command. Correct any errors.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

## Next Steps

After you have pushed your code, move on to part 2.
