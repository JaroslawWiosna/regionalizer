#pragma once
#include "../Coordinate/Coordinate.hpp"

class Latitude : public Coordinate {
public:
  Latitude(double angle) : Coordinate{angle} {}
  Latitude(std::string str) : Latitude{std::stod(str)} {}

  std::string print();
  std::string to_string();
  /*
  private:
      double angle;
  */
};
