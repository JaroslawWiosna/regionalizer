/**
 * \class Region
 * @file Region.hpp
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef REGION_HPP
#define REGION_HPP

#include "City.hpp"
#include "DatabaseReader.hpp"
#include "GnuplotHandler.hpp"
#include "ProgressBar.hpp"
#include "VectorOfCities.hpp"
#include <algorithm>
#include <experimental/filesystem>
#include <random>
#include <vector>

namespace fs = std::experimental::filesystem;

class Region
{
  public:
    /**
     */
    explicit Region() {
    }

    explicit Region(const fs::path &databaseFile)
        : vec{DatabaseReader::readCitiesFromFile(databaseFile)} {
        setDistanceToTheFarthestInTheWholeVector();
    }

    std::vector<Region> regionalize(std::string numberOfRegions);
    std::vector<Region> regionalize(unsigned numberOfRegions);

    void plotPopulationAnimated();

    /**
     * @brief  getter
     */
    std::string getName() const;
    std::string getCapital() const;

    void setName(std::string givenName);

    std::size_t getHappinessLevel() const;
    std::vector<City> getVec() const {
        return vec;
    }

  private:
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
     */

    void setDistanceToTheFarthestInTheWholeVector();

    void push_back(City city);

    std::string calculateBestCapital() const;
    std::size_t getPopulation() const;

    /**
     * @var Region::name
     * Name of the region.
     */
    std::string name;
    std::string capital;
    std::vector<City> vec;

    std::vector<std::string>
    calculateHappinessLevelForOneRegionByBruteForce() const;

    std::vector<unsigned> generateRandomVectorWithoutRepetition(unsigned floor,
                                                                unsigned ceil,
                                                                unsigned size);

    std::vector<std::string>
    regionalizeUsingRandom(std::string numberOfRegions);

    std::vector<std::string> regionalizeUsingRandom(unsigned numberOfRegions);

    std::vector<Region>
    makeSubregionsBasedOnElectedCapitals(std::vector<std::string> capitals);

    std::vector<City> sortVec();
};

#endif // REGION_HPP
