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
#include <algorithm>
#include <cmath> // abs
#include <string>
#include <vector>
//#include <memory>
//#include <utility>
//#include <type_traits>
#include "City.hpp"
#include <random>

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
void setDistanceToTheFarthestInTheWholeVector(std::vector<City> &vec);

/**
 * @brief get sum of Cities population inside the given vector
 *
 * @param[in] std::vector<City>& vec
 */
std::size_t getPopulationOfTheWholeVector(const std::vector<City> &vec);

/**
 * @brief "returns" City that is the best capital
 *
 * @param[in] std::vector<City>& vec
 */
std::vector<std::string>
calculateHappinessLevelForOneRegionByBruteForce(std::vector<City> vec);

std::vector<unsigned> generateRandomVectorWithoutRepetition(unsigned floor,
                                                            unsigned ceil,
                                                            unsigned size);

/**
 * @brief regionalize using random checking
 */
std::vector<std::string> regionalizeUsingRandom(std::vector<City> vec,
                                                std::string numberOfRegions);

/**
 * @brief regionalize using random checking
 */
std::vector<std::string> regionalizeUsingRandom(std::vector<City> vec,
                                                unsigned numberOfRegions);

/**
 * @brief NOT SAFE TO USE YET
 *
 * @param[in] std::vector<City>& vec
 */
std::vector<std::string>
calculateHappinessLevelForTwoRegionsByBruteForce(const std::vector<City> &vec);

std::vector<City> sortVec(const std::vector<City> &vec);

} // namespace VectorOfCities

#endif // VECTOROFCITIES_HPP
