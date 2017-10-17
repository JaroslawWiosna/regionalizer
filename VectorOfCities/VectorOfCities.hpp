/**
 * \file VectorOfCities
 *
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

void setDistanceToTheFarthestInTheWholeVector(std::vector<City>& vec);
std::size_t getPopulationOfTheWholeVector(const std::vector<City>& vec);
void calculateHappinessLevelForOneRegionByBruteForce(std::vector<City> vec);
void calculateHappinessLevelForTwoRegionsByBruteForce(const std::vector<City>& vec);
std::vector<City> sortVec(const std::vector<City>& vec);
}

#endif // VECTOROFCITIES_HPP

