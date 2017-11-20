/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef ClosestCity_HPP
#define ClosestCity_HPP

#include "City.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

namespace ClosestCity {

/**
 * @brief removes from vector of cities records of cities that has lower
 * population that the city we look for
 *
 * @param[in] std::vector<City>& vec
 * @param[in] std::string cityName
 */
void removeCitiesInVectorThatAreSmallerThanMe(std::vector<City> &vec,
                                              const std::string &cityName);

/**
 * @brief after removing the cities with lower population it calculates the
 * distance from all the ctites to the given city named like cityName. Later it
 * go trough the list of the cities not erased and looks up for the closest to
 * the cityName until the end of the list. We return finally the closest city.
 *
 * @param[in] std::vector<City>& vec
 * @param[in] std::string cityName
 */
std::string getTheClosestCityThatIsBiggerThanMe(std::vector<City> vec,
                                                const std::string &cityName);

/**
 * @brief We make a path from the first city to the next closest city bigger
 * than the previous one until there is no bigger
 *
 * @param[in] std::vector<City>& vec
 * @param[in] std::string cityName
 */
std::string getAllBiggestCitiesInOrder(std::vector<City> vec,
                                       std::string cityName);


} // namespace ClosestCity

#endif // ClosestCity_HPP
