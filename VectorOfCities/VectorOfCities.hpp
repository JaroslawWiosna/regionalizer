/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef VECTOROFCITIES_HPP
#define VECTOROFCITIES_HPP

#include <iostream>
//#include <list>
//#include <cfloat> // FLT_MIN
#include <cmath> // abs
#include <algorithm>
#include <vector>
#include <string>
//#include <memory>
//#include <utility>
//#include <type_traits>
#include "City.hpp"

namespace VectorOfCities {

/** 
 * @brief set `distanceToTheFarthest` field in each object inside the vector
 *
 * This field can be set only when we have more than one city.
 * Otherwise `distanceToTheFarthest` is equal to zero, since the city itself
 * is the farthest.
 * 
 * This method uses `distanceFrom` method for checking the distance to each 
 * city in the vector.
 *
 * Having `distanceToTheFarthest` field set is essential for calculating 
 * Happiness Index
 *
 * @param[in] std::vector<City>& vec
 */ 
void setDistanceToTheFarthestInTheWholeVector(std::vector<City>& vec);

/**
 * @brief get sum of Cities population inside the given vector
 *
 * @param[in] std::vector<City>& vec
 */ 
std::size_t getPopulationOfTheWholeVector(const std::vector<City>& vec);

/**
 * @brief "returns" City that is the best capital
 *
 * @param[in] std::vector<City>& vec
 */
void calculateHappinessLevelForOneRegionByBruteForce(std::vector<City> vec);

/**
 * @brief NOT SAFE TO USE YET
 *
 * @param[in] std::vector<City>& vec
 */
void calculateHappinessLevelForTwoRegionsByBruteForce
    (const std::vector<City>& vec);

std::vector<City> sortVec(const std::vector<City>& vec);

}

#endif // VECTOROFCITIES_HPP

