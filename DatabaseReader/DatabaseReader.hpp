/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef DATABASEREADER_HPP
#define DATABASEREADER_HPP

#include "City.hpp"
#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace DatabaseReader {

namespace fs = std::experimental::filesystem;

/**
 * @brief read data from file and returns a vector of Cities
 *
 * @param[in] std::string databaseFile
 * path to the file with data
 *
 * @return std::vector<City>
 * Vector of cities
 */
std::vector<City> readCitiesFromFile(const fs::path &databaseFile);

/**
 * @brief helper method to parse databaseFile
 * @todo: move to separate file? utils perhaps?
 */
void split(std::string str, std::string splitBy,
           std::vector<std::string> &tokens);

} // namespace DatabaseReader

#endif // DATABASEREADER_HPP
