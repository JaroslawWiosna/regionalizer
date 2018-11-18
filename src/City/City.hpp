#pragma once
#include "../Latitude/Latitude.hpp"
#include "../Longitude/Longitude.hpp"
#include <iostream>
#include <memory>

class City {
public:
  /*
      explicit City(std::string name, Latitude latitude, Longitude longitude,
     std::size_t population) : name{name}, latitude{latitude},
     longitude{longitude}, population{population} {}
      explicit City(std::string name, Latitude latitude, Longitude longitude) :
     City{name, latitude, longitude, 0} {}
  */
  explicit City(std::string name, Latitude latitude, Longitude longitude,
                std::size_t population);
  explicit City(std::string name, Latitude latitude, Longitude longitude)
      : City{name, latitude, longitude, 0} {}



  std::string name() const;
  std::size_t population() const;

  void print();
  double distanceTo(const City &secondCity) const;
  static double haversineFormula(double Alat, double Alon, double Blat,
                                 double Blon);
  /*
      std::string name;
      Latitude latitude;
      Longitude longitude;
      std::size_t population;
  */

private:
  struct Impl;
  std::shared_ptr<Impl> pImpl;
};
