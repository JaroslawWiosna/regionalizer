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

#include "DatabaseReader.hpp"
#include "VectorOfCities.hpp"

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class Region
{
  public:
    /**
     */
    explicit Region(const fs::path &databaseFile)
        : vec{DatabaseReader::readCitiesFromFile(databaseFile)} {
        VectorOfCities::setDistanceToTheFarthestInTheWholeVector(vec);
    }

    void regionalize(std::string numberOfRegions);
    void regionalize(unsigned numberOfRegions);

    void plotPopulationAnimated();

    /**
     * @brief  getter
     */
    std::string getName() const;

  private:
    /**
     * @var Region::name
     * Name of the region.
     */
    std::string name;
    std::vector<City> vec;
};

#endif // REGION_HPP
