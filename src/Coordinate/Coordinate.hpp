#pragma once
#include <string>

class Coordinate {
public:
  virtual std::string print() = 0;
  virtual std::string to_string() = 0;
  double get();

protected:
  Coordinate(double angle) : angle(angle) {}

public:
  double angle;
};
