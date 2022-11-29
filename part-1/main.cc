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

#include <iostream>
#include <string>
#include <vector>

#include "states.h"

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
