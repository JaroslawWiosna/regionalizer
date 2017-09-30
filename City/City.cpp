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

City::City(std::string name,
        std::size_t area,
        std::size_t population,
        std::string latitude,
        std::string longitude) : 
            name{name},
	    area{area},
	    population{population},
	    latitude{latitude},
	    longitude{longitude} {

}

City::City(std::string name,
        std::string area,
        std::string population,
        std::string latitude,
        std::string longitude) : 
            name{name},
	    area{0},
	    population{0},
	    latitude{latitude},
	    longitude{longitude} {
    area = std::stoi(area);
    population = std::stoi(population);
}
    
double City::distanceFrom(City differentCity) {
   // below we have Coordinates as decimal values
   // It means that 21E30' would be 21.5
   //               21E45' would be 21.75, and so on...
   // TODO: move this explanation into doxygen comment

   // A = this city
   // B = differentCity

   // TODO: convert this->latitude to Alat
   // TODO: convert this->longitude to Alon
   // TODO: convert differentCity.latitude to Blat
   // TODO: convert differentCity.latitude to Blon
    double Alat = 51.75;
    double Alon = 19.49; //19deg 27' 17''
    double Blat = 51.24; // 51deg 13' 56''
    double Blon = 21.01; //21deg 00' 30''

    constexpr double R = 6371;
    // TODO: implement generic function for radian conversion
    // like Alat = utils::degreesToRadians(Alat);
    // (consider creating utils directory with namespace 'utils'
    Alat = Alat * 3.14 / 180.0; // to_radians
    Alon = Alon * 3.14 / 180.0; // to_radians
    Blat = Blat * 3.14 / 180.0; // to_radians
    Blon = Blon * 3.14 / 180.0; // to_radians
    double deltaLat = Blat - Alat;
    double deltaLon = Blon - Alon;

    double a = pow(sin(0.5 * deltaLat),2) + cos(Alat) * cos(Blat) * pow(sin(0.5 * deltaLon),2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double d = R * c;

    return d;
}
 
std::string City::getName() {
    return name;
}

std::size_t City::getArea() {
    return area;
}

std::size_t City::getPopulation() {
    return population;
}

std::string City::getLatitude() {
    return latitude;
}

std::string City::getLongitude() {
    return longitude;
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
    return res;
}


