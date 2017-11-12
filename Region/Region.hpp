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

    void setName(std::string givenName);

    std::size_t getHappinessLevel() const;

    const Region operator+(const Region &) const;
    Region &operator+=(const Region &);
    const Region operator-(const Region &) const = delete;
    Region &operator-=(const Region &) = delete;
    const Region operator*(const Region &)const = delete;
    Region &operator*=(const Region &) = delete;
    const Region operator/(const Region &) const = delete;
    Region &operator/=(const Region &) = delete;
    Region operator%(const Region &) = delete;
    bool operator==(const Region &) = delete;
    bool operator>(const Region &) = delete;
    bool operator<(const Region &) = delete;
    bool operator>=(const Region &) = delete;
    bool operator<=(const Region &) = delete;

    const Region operator+(const City &) const;
    Region &operator+=(const City &);
    const Region operator-(const City &) const = delete;
    Region &operator-=(const City &) = delete;
    const Region operator*(const City &)const = delete;
    Region &operator*=(const City &) = delete;
    const Region operator/(const City &) const = delete;
    Region &operator/=(const City &) = delete;
    Region operator%(const City &) = delete;
    bool operator==(const City &) = delete;
    bool operator>(const City &) = delete;
    bool operator<(const City &) = delete;
    bool operator>=(const City &) = delete;
    bool operator<=(const City &) = delete;

    /**
     * @brief  getter
     */
    std::string getName() const;
    std::string getCapital() const;
    std::vector<City> getVec() const;
    std::size_t getPopulation() const;


  private:

    /**
     * @var Region::name
     * Name of the region.
     */
    std::string name;

    /**
     * @var Region::capital
     * Name of the capital.
     */
    std::string capital;

    /**
     * @var Region::vec
     * Vector of cities.
     */
    std::vector<City> vec;


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
