/**
 * \class City
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef CITY_HPP
#define CITY_HPP

#include <iostream>
//#include <list>
//#include <cfloat> // FLT_MIN
#include <cmath> // abs
//#include <algorithm>
//#include <vector>
#include <string>
//#include <memory>
//#include <utility>
//#include <type_traits>

class City{
  public: 
    explicit City() : 
        name{""}, 
        area{0},
	population{0},
	latitude{"30N40'40''"},
	longitude{"15E0'0''"} {

    }
    
    City(std::string name,
        std::size_t area,
        std::size_t population,
        std::string latitude,
        std::string longitude
    );
    
    double distanceFrom(City differentCity);
    std::string getName();
    std::size_t getArea();
    std::size_t getPopulation();
    std::string getLatitude();
    std::string getLongitude();
    std::string getAllFields();
  private:
    std::string name;
    std::size_t area;
    std::size_t population;
    std::string latitude;
    std::string longitude;
};

#endif // CITY_HPP

