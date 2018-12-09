#pragma once
#include "../Coordinate/Coordinate.hpp"

class Longitude : public Coordinate {
public:
  Longitude(double angle) : Coordinate{angle} {}
  explicit Longitude(const std::string& str) : Longitude{std::stod(str)} {}

  std::string print();
  std::string to_string();
  /*
  private:
      double angle;
  */
};
