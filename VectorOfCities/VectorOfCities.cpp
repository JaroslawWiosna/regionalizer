/**
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

std::size_t getPopulationOfTheWholeVector(const std::vector<City>& vec) {
    std::size_t result{};
    for (const auto & i : vec) {
        result += i.getPopulation();
    }
    return result;
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
    std::cout << "Population = " << getPopulationOfTheWholeVector(vec);
    std::cout << std::endl;
    std::cout << "Percentage = " << static_cast<double>(10.0 * bestHLsoFar) 
        / getPopulationOfTheWholeVector(vec) << "%";
    std::cout << std::endl;

}

void calculateHappinessLevelForTwoRegionsByBruteForce(const std::vector<City>& vec) {
    std::string bestCapitalsSoFar{};
    std::size_t bestHLsoFar{};
    auto sortedVec = sortVec(vec);
    auto it = sortedVec.begin();
    auto jt = it;
    for (; it != sortedVec.begin()+8 ; ++it ) {
        for (jt = it + 1; jt != sortedVec.begin()+9 ; ++jt ) {
            std::cout << it->getName() << " " << jt->getName() << "\n";
	    std::size_t hl{};
	    for (const auto& i : sortedVec) {
                std::size_t distanceToit = i.distanceFrom(*it);
                std::size_t distanceTojt = i.distanceFrom(*jt);
                std::size_t distanceToTheClosestCapital = distanceToit > 
                        distanceTojt ? distanceTojt : distanceToit;
	        std::size_t tmp = (10.0 - 
                        ((static_cast<double>(distanceToTheClosestCapital) / 
                        static_cast<double>(i.getDistanceToTheFarthest()))*10.0));
	        hl += (i.getPopulation() * tmp);
	    }
	    std::cout << "Happiness level = " << hl;
            std::cout << std::endl;
            if (hl > bestHLsoFar) {
	        bestHLsoFar = hl;
	        bestCapitalsSoFar = it->getName() + "+" + jt->getName();
	    }
	}
    }
    std::cout << std::endl;
    std::cout << "The best capitals would be  " << bestCapitalsSoFar;
    std::cout << std::endl;
    std::cout << "Happiness level = " << bestHLsoFar;
    std::cout << std::endl;
    std::cout << "Population = " << getPopulationOfTheWholeVector(vec);
    std::cout << std::endl;
    std::cout << "Percentage = " << static_cast<double>(10.0 * bestHLsoFar) 
        / getPopulationOfTheWholeVector(vec) << "%";
    std::cout << std::endl;
}

std::vector<City> sortVec(const std::vector<City>& vec) {
    auto sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end(), [](const City& lhs, const City& rhs) {
        return lhs.getPopulation() > rhs.getPopulation();
	});
    return sortedVec;    
}

} // namespace
