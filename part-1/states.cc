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

State::State(const std::string& name, int population, double land_area)

    : name_(name), population_(population), land_area_(land_area) {}

State::State() : population_(), land_area_() {}

const std::string& State::Name() const { return name_; }

int State::Population() const { return population_; }

double State::LandArea() const { return land_area_; }

double State::PopulationDensity() const {
  double density = population_ / land_area_;

  return density;
}

std::vector<State> ReadStates(const std::string& csv_filename) {
  std::vector<std::vector<std::string>> contensts = ReadCSV(csv_filename, 48);
  std::vector<State> states;
  for (int rowt = 0; rowt < contensts.size(); rowt++) {
    std::vector<std::string> row = contensts.at(rowt);
    if (rowt == 0) {
      continue;
    }
    std::string name;
    int population = 0;
    double land_area = 0.0;
    for (int column = 0; column < row.size(); column++) {
      if (column == 0) {
        name = row.at(column);
      } else if (column == 2) {
        population = std::stoi(row.at(column));
      } else if (column == 47) {
        land_area = std::stod(row.at(column));
      }
    }
    State t(name, population, land_area);
    states.push_back(t);
  }

  return states;
}
