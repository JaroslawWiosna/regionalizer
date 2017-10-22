/**
 * \class City
 * @file City.hpp
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
/** 
 * @brief explicit Ctor with empty name, zero area and zero population,
 * some dummy coordinates. Never meant to be used..., for now.
 */ 
    explicit City() : 
        name{""}, 
        area{0},
	population{0},
	latitude{"30N40'40''"},
	longitude{"15E0'0''"},
        distanceToTheFarthest{0} {
    }

/**
 * @brief Secondary ctor of Class City.
 * That is because of area and population types which is arithmetic here.
 * Mainly Cities are constructed based on std::string as area and population
 * types.
 *
 * @param[in] name
 * @param[in] area
 * @param[in] population
 * @param[in] latitude
 * @param[in] longitude
 */
    City(std::string name,
        std::size_t area,
        std::size_t population,
        std::string latitude,
        std::string longitude
    );

/** 
 * @brief Primary ctor of Class City
 * Every single one of arguments are std::string
 * area and population fields are arithmetic, so conversion is needed.
 * distanceToTheFarthest is set to zero, because when object is created 
 * we know nothing about other cities. Implicitly, we are assuming that
 * `this` city is one and only in the world.
 * Later, when vector of Cities is introduced distanceToTheFarthest will be 
 * updated
 *
 * @param[in] name
 * @param[in] area
 * @param[in] population
 * @param[in] latitude
 * @param[in] longitude
 */
    City(std::string name,
        std::string area,
        std::string population,
        std::string latitude,
        std::string longitude
    );
    
 /**
  * @brief Calculate distance to other city
  * The algorithm inside is haversine formula.
  *
  * below we have Coordinates as decimal values
  * It means that 21E30' would be 21.5
  *               21E45' would be 21.75, and so on...
  *
  * A = this city
  * B = differentCity
  * @param[in] City differentCity
  *
  * @return distance in kilometers
  */
    double distanceFrom(City differentCity) const;
     
 /**
  * @brief Haversine formula to calculate distance
  *
  * @param[in] Alat - latitude of the first city
  * @param[in] Alon - longitude of the first city
  * @param[in] Blat - latitude of the second city
  * @param[in] Blat - longitude of the second city
  *
  * @TODO a short explanation of the formula would be useful
  * @TODO this method does NOT use any of the class fields and can be moved
  * to some other file (namespace utils perhaps?)
  *
  * @return distance in kilometers
  */
    double haversineFormula
        (double Alat, double Alon, double Blat, double Blon) const;
 
 /**
  * @brief distanceToTheFarthest setter
  *
  * @param[in] std::size_t distance
  *
  * @return nothing
  */
    void setDistanceToTheFarthest(std::size_t distance);

 /**
  * @brief  getter
  */
    std::string getName() const;

 /**
  * @brief  getter
  */
    std::size_t getArea() const;

 /**
  * @brief  getter
  */
    std::size_t getPopulation() const;

 /**
  * @brief  getter
  */
    std::string getLatitude() const;

 /**
  * @brief  getter
  */
    std::string getLongitude() const;

 /**
  * @brief  getter
  */
    std::size_t getDistanceToTheFarthest() const;

 /**
  * @brief  getter
  */
    std::string getAllFields();
  private:
 /**
  * @var City::name
  * Name of the city.
  */
    std::string name;
    std::size_t area;
    std::size_t population;
    std::string latitude;
    std::string longitude;
    std::size_t distanceToTheFarthest;
};

#endif // CITY_HPP

