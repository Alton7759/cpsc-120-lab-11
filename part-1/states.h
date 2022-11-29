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

#ifndef STATES_H
#define STATES_H

#include <string>
#include <vector>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns);

class State {
 public:
  State(const std::string& name, int population, double land_area);

  State();

  const std::string& Name() const;
  int Population() const;
  double LandArea() const;

  double PopulationDensity() const;

 private:
  std::string name_;
  int population_;
  double land_area_;
};

std::vector<State> ReadStates(const std::string& csv_filename);

#endif  // STATES_H_
