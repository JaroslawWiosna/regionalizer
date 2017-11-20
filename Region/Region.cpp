/**
 * \class Region
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "Region.hpp"

std::string Region::getName() const {
    return name;
}

std::vector<Region> Region::regionalize(std::string numberOfRegions) {
    return regionalize(std::stoi(numberOfRegions));
}

std::vector<Region> Region::regionalize(unsigned numberOfRegions) {
    std::vector<std::string> capitals{};
    std::vector<Region> subregions{};
    if (numberOfRegions == 1) {
        capitals = calculateHappinessLevelForOneRegionByBruteForce();
    } else {
        capitals = regionalizeUsingRandom(numberOfRegions);
    }

    ProgressBar *bar = new ProgressBar{"make subregions"};
    for (int i = 0; i < 25; ++i) {
        bar->printBar(i * 4);
        subregions = makeSubregionsBasedOnElectedCapitals(capitals);
        capitals.clear();
        for (auto subregion : subregions) {
            capitals.push_back(subregion.getCapital());
        }
    }
    delete bar;

    GnuplotHandler::plotHappinessIndex(vec, capitals);
    return subregions;
}

void Region::plotPopulationAnimated() {
    GnuplotHandler::plotPopulationAnimated(vec);
}

void Region::setName(std::string givenName) {
    name = givenName;
}

// TODO implement
std::size_t Region::getHappinessLevel() const {
    return 0;
}

const Region Region::operator+(const Region &rhs) const {
    Region result = *this;
    result += rhs;
    return result;
}

Region &Region::operator+=(const Region &rhs) {
    auto rhsVec = rhs.getVec();
    for (auto city : rhs.getVec()) {
        this->push_back(city);
    }
    setDistanceToTheFarthestInTheWholeVector();
    return *this;
}

const Region Region::operator+(const City &rhs) const {
    Region result = *this;
    result += rhs;
    return result;
}

Region &Region::operator+=(const City &rhs) {
    this->push_back(rhs);
    setDistanceToTheFarthestInTheWholeVector();
    return *this;
}

std::string Region::getCapital() const {
    //    auto capitals = calculateHappinessLevelForOneRegionByBruteForce();
    //    return capitals.front();
    return calculateBestCapital();
}

std::vector<City> Region::getVec() const {
    return vec;
}

std::size_t Region::getPopulation() const {
    std::size_t result{};
    for (const auto &i : vec) {
        result += i.getPopulation();
    }
    return result;
}

// private:

void Region::setDistanceToTheFarthestInTheWholeVector() {
    for (City &i : vec) {
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

void Region::push_back(City city) {
    vec.push_back(city);
    //    setDistanceToTheFarthestInTheWholeVector();
}

std::string Region::calculateBestCapital() const {
    std::vector<std::string> bestCapitalSoFar{};
    std::size_t bestHLsoFar{};
    for (City i : vec) {
        std::size_t hl{}; // happiness level
        for (City j : vec) {
            std::size_t tmp =
                (10.0 - ((static_cast<double>(j.distanceFrom(i)) /
                          static_cast<double>(j.getDistanceToTheFarthest())) *
                         10.0));
            hl += (j.getPopulation() * tmp);
        }
        if (hl > bestHLsoFar) {
            bestHLsoFar = hl;
            bestCapitalSoFar.clear();
            bestCapitalSoFar.push_back(i.getName());
        }
    }
    return bestCapitalSoFar.front();
}

std::vector<std::string>
Region::calculateHappinessLevelForOneRegionByBruteForce() const {
    std::vector<std::string> bestCapitalSoFar{};
    std::size_t bestHLsoFar{};
    for (City i : vec) {
        // std::cout << " " << i.getName() << "\t";
        std::size_t hl{}; // happiness level
        for (City j : vec) {
            std::size_t tmp =
                (10.0 - ((static_cast<double>(j.distanceFrom(i)) /
                          static_cast<double>(j.getDistanceToTheFarthest())) *
                         10.0));
            hl += (j.getPopulation() * tmp);
        }
        // std::cout << "Happiness level = " << hl;
        // std::cout << std::endl;
        if (hl > bestHLsoFar) {
            bestHLsoFar = hl;
            bestCapitalSoFar.clear();
            bestCapitalSoFar.push_back(i.getName());
        }
    }
    std::cout << std::endl;
    std::cout << "The best capitals would be ";
    for (auto i : bestCapitalSoFar) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Happiness level = " << bestHLsoFar;
    std::cout << std::endl;
    std::cout << "Population = " << getPopulation();
    std::cout << std::endl;
    std::cout << "Percentage = "
              << static_cast<double>(10.0 * bestHLsoFar) / getPopulation()
              << "%";
    std::cout << std::endl;

    return bestCapitalSoFar;
}


std::vector<unsigned>
Region::generateRandomVectorWithoutRepetition(unsigned floor, unsigned ceil,
                                              unsigned size) {
    RandomNumberGeneratorInteger generator{floor, ceil};
    return generator.generateRandomVectorWithoutRepetition(size);
}

std::vector<std::string>
Region::regionalizeUsingRandom(std::string numberOfRegions) {
    return Region::regionalizeUsingRandom(std::stoi(numberOfRegions));
}

std::vector<std::string>
Region::regionalizeUsingRandom(unsigned numberOfRegions) {
    std::cout << "regionalizeUsingRandom \n";
    std::cout << "number of regions = " << numberOfRegions << "\n";

    constexpr std::size_t tries{100};
    std::vector<std::string> bestCapitalsSoFar{};
    std::size_t bestHLsoFar{};
    auto sortedVec = sortVec();

    ProgressBar *bar = new ProgressBar{"regionalizeUsingRandom"};
    for (std::size_t i{}; i < tries; ++i) {
        bar->printBar(100 * i / tries);
        auto vecOfRand = generateRandomVectorWithoutRepetition(
            0, sortedVec.size() - 1, numberOfRegions);
        //      for (auto j : vecOfRand) { std::cout << j << "-";} std::cout <<
        //      "\n";
        std::size_t hl{};
        for (City j : sortedVec) {
            std::size_t bestTmpSoFar{};
            for (auto x : vecOfRand) {
                std::size_t tmp =
                    (10.0 -
                     ((static_cast<double>(j.distanceFrom(sortedVec[x])) /
                       static_cast<double>(j.getDistanceToTheFarthest())) *
                      10.0));
                if (tmp > bestTmpSoFar) {
                    bestTmpSoFar = tmp;
                }
            }
            hl += (j.getPopulation() * bestTmpSoFar);
        }
        if (hl > bestHLsoFar) {
            bestHLsoFar = hl;
            bestCapitalsSoFar.clear();
            for (auto it = vecOfRand.begin(); it != vecOfRand.end(); ++it) {
                bestCapitalsSoFar.push_back(sortedVec[*it].getName());
            }
        }
    }
    delete bar;
    std::cout << "The best capitals would be ";
    for (auto i : bestCapitalsSoFar) {
        if (i == bestCapitalsSoFar[bestCapitalsSoFar.size() - 1]) {
            std::cout << i;
        } else {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Happiness level = " << bestHLsoFar;
    std::cout << std::endl;
    std::cout << "Population = " << getPopulation();
    std::cout << std::endl;
    std::cout << "Percentage = "
              << static_cast<double>(10.0 * bestHLsoFar) / getPopulation()
              << "%";
    std::cout << std::endl;

    return bestCapitalsSoFar;
}

std::vector<Region> Region::makeSubregionsBasedOnElectedCapitals(
    std::vector<std::string> capitals) {
    std::vector<Region> subregions;
    subregions.reserve(capitals.size());

    for (auto &capital : capitals) {
        Region tmp{};
        subregions.push_back(tmp);
        subregions.back().setName(capital);
    }

    for (auto &region : subregions) {
        region.setDistanceToTheFarthestInTheWholeVector();
    }

    for (auto &city : vec) {
        std::string closestCapitalSoFar{};
        std::size_t distanceToClosestCapital{city.getDistanceToTheFarthest()};
        for (const auto &capital : capitals) {
            auto it = std::find_if(
                std::begin(vec), std::end(vec),
                [&](City const &c) { return c.getName() == capital; });
            if (city.distanceFrom(*it) < distanceToClosestCapital) {
                distanceToClosestCapital = city.distanceFrom(*it);
                closestCapitalSoFar = it->getName();
            }
        }
        auto it = std::find_if(std::begin(subregions), std::end(subregions),
                               [&](Region const &r) {
                                   return r.getName() == closestCapitalSoFar;
                               });
        it->push_back(city);
    }
    return subregions;
}

std::vector<City> Region::sortVec() {
    auto sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end(),
         [](const City &lhs, const City &rhs) {
             return lhs.getPopulation() > rhs.getPopulation();
         });
    return sortedVec;
}
