#include "City.hpp"
#include <cmath>

struct City::Impl {
  Impl(std::string name, Latitude latitude, Longitude longitude,
       std::size_t population)
      : name{name}, latitude{latitude}, longitude{longitude}, population{
                                                                  population} {


      std::cout << "\t\t\t city ctor\n";
  }

  std::string name;
  Latitude latitude;
  Longitude longitude;
  std::size_t population;
};

City::City(std::string name, Latitude latitude, Longitude longitude,
           std::size_t population)
    : pImpl{std::make_unique<Impl>(name, latitude, longitude, population)} {}

std::string City::name() const{
    return pImpl->name;
}

std::size_t City::population() const{
    return pImpl->population;
}

void City::print() {
  std::cout << "Name: " << pImpl->name
            << "\nLat: " << pImpl->latitude.to_string() << "\nLong"
            << pImpl->longitude.to_string()
            << "\nPopulation: " << pImpl->population << "\n";
}

double City::distanceTo(const City& secondCity) const {
    return haversineFormula(pImpl->latitude.get(), pImpl->longitude.get(), secondCity.pImpl->latitude.get(), secondCity.pImpl->longitude.get());
}

double City::haversineFormula(double Alat, double Alon, double Blat,
                               double Blon) {
    constexpr double R = 6371;
    Alat = Alat * 3.14 / 180.0; // to_radians
    Alon = Alon * 3.14 / 180.0; // to_radians
    Blat = Blat * 3.14 / 180.0; // to_radians
    Blon = Blon * 3.14 / 180.0; // to_radians
    double deltaLat = Blat - Alat;
    double deltaLon = Blon - Alon;

    double a = pow(sin(0.5 * deltaLat), 2) +
               cos(Alat) * cos(Blat) * pow(sin(0.5 * deltaLon), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = R * c;

    return d;
}

