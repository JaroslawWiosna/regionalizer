/**
 * \class City
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "City.hpp"

City::City(const std::string &name, std::size_t area, std::size_t population,
           const std::string &latitude, const std::string &longitude)
    : name{name}, area{area}, population{population}, latitude{latitude},
      longitude{longitude}, distanceToTheFarthest{0} {
}

City::City(const std::string &name, const std::string &area,
           const std::string &population, const std::string &latitude,
           const std::string &longitude)
    : name{name}, area{0}, population{0}, latitude{latitude},
      longitude{longitude}, distanceToTheFarthest{0} {
    this->area = std::stoi(area);
    this->population = std::stoi(population);
}

double City::distanceFrom(City differentCity) const {
    double Alat = std::stod(this->latitude);
    double Alon = std::stod(this->longitude);
    double Blat = std::stod(differentCity.latitude);
    double Blon = std::stod(differentCity.longitude);

    return haversineFormula(Alat, Alon, Blat, Blon);
}

double City::haversineFormula(double Alat, double Alon, double Blat,
                              double Blon) const {
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

void City::setDistanceToTheFarthest(std::size_t distance) {
    distanceToTheFarthest = distance;
}

std::string City::getName() const {
    return name;
}

std::size_t City::getArea() const {
    return area;
}

std::size_t City::getPopulation() const {
    return population;
}

std::string City::getLatitude() const {
    return latitude;
}

std::string City::getLongitude() const {
    return longitude;
}

std::size_t City::getDistanceToTheFarthest() const {
    return distanceToTheFarthest;
}

std::string City::getAllFields() {
    std::string res{};
    res += name;
    res += " ";
    res += std::to_string(area);
    res += " ";
    res += std::to_string(population);
    res += " ";
    res += latitude;
    res += " ";
    res += longitude;
    res += " ";
    res += std::to_string(distanceToTheFarthest);
    res += " ;";
    return res;
}
