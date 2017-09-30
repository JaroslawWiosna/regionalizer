/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "DatabaseReader.hpp"

std::vector<City> readCitiesFromFile(std::string databaseFile) {
    std::vector<City> vecOfCities;
    std::ifstream ifs;
    ifs.open(databaseFile, std::ifstream::in);
    std::string line{};
    std::size_t len;

    while(std::getline(ifs, line)) {
        if (line[0] == '#') {
            continue;
	}
	std::string lineToParse{line};
        len = lineToParse.length();

        std::string::size_type posDelimiterCity = line.find('-');
        std::string name{line.substr(0, posDelimiterCity)};
	lineToParse = lineToParse.substr(posDelimiterCity, len);

	// TODO: not working yet...
//        std::string::size_type posDelimiterArea = lineToParse.find('-');
//        std::string area{lineToParse.substr(posDelimiterCity, posDelimiterArea)};
        //City city(name, std::stol(area), 0, name, name);
        City city(name, 0, 0, name, name);
	vecOfCities.push_back(city);
    }

    return vecOfCities;
}

