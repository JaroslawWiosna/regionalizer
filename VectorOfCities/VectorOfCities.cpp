/**
 * \file VectorOfCities
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "VectorOfCities.hpp"

namespace VectorOfCities {

void setDistanceToTheFarthestInTheWholeVector(std::vector<City>& vec) {
    for (City& i : vec) {
	double farthestDistanceSoFar{};
        for (City j : vec) {
	    double tmp = i.distanceFrom(j);
	    if (tmp > farthestDistanceSoFar) {
                farthestDistanceSoFar = tmp;
	    }
	}
        i.setDistanceToTheFarthest(farthestDistanceSoFar);	
    }
}

void calculateHappinessLevelForOneRegionByBruteForce(std::vector<City> vec){ 
    std::string bestCapitalSoFar{};
    std::size_t bestHLsoFar{};
    for (City i : vec) {
        std::cout << " " << i.getName() << "\t";
	std::size_t hl{}; // happiness level
        for (City j : vec) {
	    std::size_t tmp = (10.0 - ((static_cast<double>(j.distanceFrom(i)) / 
                    static_cast<double>(j.getDistanceToTheFarthest()))*10.0));
	    hl += (j.getPopulation() * tmp);
	}
	std::cout << "Happiness level = " << hl;
        std::cout << std::endl;
        if (hl > bestHLsoFar) {
	    bestHLsoFar = hl;
	    bestCapitalSoFar = i.getName();
	}
    }
    std::cout << std::endl;
    std::cout << "The best capital would be  " << bestCapitalSoFar;
    std::cout << std::endl;
    std::cout << "Happiness level = " << bestHLsoFar;
    std::cout << std::endl;

}

} // namespace
