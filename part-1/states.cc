// Wilfredo Rodas
// CPSC 120-01
// 2022-11-28
// rodaswilfredo24@csu.fullerton.edu
// @rodasw24
//
// Lab 11-01
// Partners: @AHan003, @alton7759
//
// Object-oriented State class.
//

#include "states.h"

#include <fstream>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns) {
  std::vector<std::vector<std::string>> table;
  std::ifstream file(csv_filename);

  // read each row
  while (file.good()) {
    std::vector<std::string> row;
    // read each column
    for (int i = 0; i < columns; ++i) {
      std::string cell;
      file.ignore(1, '"');  // leading quote
      std::getline(file, cell, '"');
      if (i < (columns - 1)) {
        file.ignore(1, ',');  // comma
      }
      row.push_back(cell);
    }
    if (file.good()) {
      table.push_back(row);
    }
  }

  return table;
}

State::State(const std::string& name, int population, double land_area) {
  // TODO: complete the definition of this constructor.
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
  const std::string& name;
  const State;
  int population = 0;
  double land_area = 0.0;
}

State::State() {
  // Since this is a constructor, it should use a member initialization list
  // to initialize data members.
  // When you are done, delete this comment.
  const
  int population_
}

const std::string& State::Name() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return ""; // TODO: replace this return statement with one that actually works
}

int State::Population() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return 0; // TODO: replace this return statement with one that actually works
}

double State::LandArea() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: This is a simple accessor function. The function definition only
  // needs to be a single statement.
  return 0.0; // TODO: replace this return statement with one that actually works
}

double State::PopulationDensity() const {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: Population density is the population divided by the land area.
  return 0.0; // TODO: replace this return statement with one that actually works
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  // TODO: write statements to implement this function, and delete this comment
  // Hint: this function should:
  //  - create an empty vector of States
  //  - call ReadCSV to create a 2D vector of strings
  //  - loop through each row of the CSV
  //    - skip the first row that contains a header
  //    - for all other rows:
  //      - get the name (as a string) from column 0
  //      - get the population (as a string) from column 2
  //        convert the string to an int with std::stoi
  //      - get the land area (as a string) from column 47
  //        convert the string to a double with std::stod
  //      - create a State object with the name, population, land area
  //      - add the State to your vector with push_back
  return std::vector<State>(); // TODO: replace this return statement with one that actually works
}
