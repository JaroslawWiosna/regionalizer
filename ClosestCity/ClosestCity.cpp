/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "ClosestCity.hpp"

namespace ClosestCity {

void removeCitiesInVectorThatAreSmallerThanMe(std::vector<City> &vec,
                                              const std::string &cityName) {
    auto city = std::find_if(vec.begin(), vec.end(),
                             [cityName](const City &city_on_list) {
                                 return (city_on_list.getName() == (cityName));
                             });
    std::size_t cityNamePopulation = city->getPopulation();
    for (unsigned element_nr = 0; element_nr < vec.size(); element_nr++) {
        if (vec[element_nr].getPopulation() < cityNamePopulation) {
            vec.erase(vec.begin() + element_nr);
            element_nr--;
        }
    }
}

std::string getTheClosestCityThatIsBiggerThanMe(std::vector<City> vec,
                                                const std::string &cityName) {
    if (vec.size() > 1) {
        std::string bestResultSoFar = "";

        auto specifiedCity = std::find_if(
            vec.begin(), vec.end(), [cityName](const City &city_on_list) {
                return (city_on_list.getName() == cityName);
            });

        auto distanceToTheClosestCity = std::numeric_limits<std::size_t>::max();

        for (auto city : vec) {
            if (city.getPopulation() > specifiedCity->getPopulation()) {
                if (city.distanceFrom(*specifiedCity) <
                    distanceToTheClosestCity) {
                    bestResultSoFar = city.getName();
                    distanceToTheClosestCity =
                        city.distanceFrom(*specifiedCity);
                }
            }
        }
        return bestResultSoFar;
    } else {
        return " ";
    }
}
std::string getAllBiggestCitiesInOrder(std::vector<City> vec,
                                       std::string cityName) {
    std::string cities_list = cityName;
    std::string next_city_in_line = "";
    while (cityName != " ") {
        removeCitiesInVectorThatAreSmallerThanMe(vec, cityName);
        next_city_in_line = getTheClosestCityThatIsBiggerThanMe(vec, cityName);
        if (next_city_in_line != " ") {
            cities_list += ("->") + next_city_in_line;
        }
        cityName = next_city_in_line;
    }
    return cities_list;
}

} // namespace ClosestCity
