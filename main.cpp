/**
 * \class main
 * @file main.cpp
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "FlagParser.hpp"
#include "DatabaseReader.hpp"
#include "GnuplotHandler.hpp"
#include "VectorOfCities.hpp"
#include "help.txt.hpp"

int main(int argc, char *argv[]) {
    // Part 1 - start - parse argv and get databaseFile
    FlagParser parser(argc, argv);
    parser.printFlags();
    auto flags = parser.getFlags();

    if (!parser.hasKey("--help")) {
	std::cout << "Help not found, so moving on...";	
	std::cout << std::endl;
    } else {
	std::cout << "Help found, so I am about to print help...";	
	std::cout << std::endl;
        std::cout << ___help_txt;
	std::cout << "Aborting....";
	std::cout << std::endl;
	return -1;
    }
    if (!flags["-list"].empty()) {
        std::cout << "Great! " << flags["-list"] << " is being processed";
	std::cout << std::endl;
    } else {
	std::cout << "No list specified!";
	std::cout << std::endl;
	std::cout << "Aborting....";
	std::cout << std::endl;
	return -1;
    } 

    std::string databaseFile{flags["-list"]};
    // Part 1 - end
    // Part 2 - start - create vector of Cities based on databaseFile
    auto vec = DatabaseReader::readCitiesFromFile(databaseFile);

    for (City i : vec) {
        std::cout << i.getAllFields();
        std::cout << std::endl;
    }

    // Part 2 - end
    // Part 3 - start - calculate distance from one city to the farthest
    
    VectorOfCities::setDistanceToTheFarthestInTheWholeVector(vec);

    for (City i : vec) {
        std::cout << i.getAllFields();
        std::cout << std::endl;
    }
    // Part 3 - end
    // Part 4 - start - by brute force check which city would be 
    // the best capital. We have only one region. 
    // This part is just for testing "happiness level" concept
    // "Happiness level" - value from 0 to 10.
    // 10 is the best, we have 10 when we are the capital, because the
    // distance to capital is equal to zero.
    // 0 is when the capital is the farthest city.
    // Formula: HL = 10 - ((distanceFrom(capital) / distanceToTheFarthest)*10)
    VectorOfCities::calculateHappinessLevelForOneRegionByBruteForce(vec);
    // Part 4 - end
    // Part <last> - start - save to gnuplot.
    if (!GnuplotHandler::isGnuplotInstalledOnHost()) {
        std::cout << "Gnuplot is not installed on host";
        std::cout << std::endl;
        std::cout << "Aborting...";
	return -1;
    }
    GnuplotHandler::saveDummyPlot();
    GnuplotHandler::plotPopulation(vec);
    GnuplotHandler::plotHappinessLevelWhenWeHaveOnlyOneRegion(vec);
    return 0;
}    
