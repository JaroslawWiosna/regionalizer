/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "VectorOfCities.hpp"

namespace VectorOfCities {

void setDistanceToTheFarthestInTheWholeVector(std::vector<City> &vec) {
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

std::size_t getPopulationOfTheWholeVector(const std::vector<City> &vec) {
    std::size_t result{};
    for (const auto &i : vec) {
        result += i.getPopulation();
    }
    return result;
}

std::vector<std::string> regionalize(std::vector<City> vec,
                                     unsigned numberOfRegions) {
    std::vector<std::string> capitals{};
    if (numberOfRegions == 1) {
        capitals = calculateHappinessLevelForOneRegionByBruteForce(vec);
    } else if (numberOfRegions == 2) {
        capitals =
            VectorOfCities::calculateHappinessLevelForTwoRegionsByBruteForce(
                vec);
    } else {
        capitals = VectorOfCities::regionalizeUsingRandom(vec, numberOfRegions);
    }
    GnuplotHandler::plotHappinessIndex(vec, capitals);
    return capitals;
}

std::vector<std::string>
calculateHappinessLevelForOneRegionByBruteForce(std::vector<City> vec) {
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
    std::cout << "Population = " << getPopulationOfTheWholeVector(vec);
    std::cout << std::endl;
    std::cout << "Percentage = "
              << static_cast<double>(10.0 * bestHLsoFar) /
                     getPopulationOfTheWholeVector(vec)
              << "%";
    std::cout << std::endl;

    return bestCapitalSoFar;
}

std::vector<std::string>
calculateHappinessLevelForTwoRegionsByBruteForce(const std::vector<City> &vec) {
    std::vector<std::string> bestCapitalsSoFar{};
    std::size_t bestHLsoFar{};
    auto sortedVec = sortVec(vec);
    auto it = sortedVec.begin();
    auto jt = it;
    for (; it != sortedVec.begin() + 8; ++it) {
        for (jt = it + 1; jt != sortedVec.begin() + 9; ++jt) {
            // std::cout << it->getName() << " " << jt->getName() << "\n";
            std::size_t hl{};
            for (const auto &i : sortedVec) {
                std::size_t distanceToit = i.distanceFrom(*it);
                std::size_t distanceTojt = i.distanceFrom(*jt);
                std::size_t distanceToTheClosestCapital =
                    distanceToit > distanceTojt ? distanceTojt : distanceToit;
                std::size_t tmp =
                    (10.0 -
                     ((static_cast<double>(distanceToTheClosestCapital) /
                       static_cast<double>(i.getDistanceToTheFarthest())) *
                      10.0));
                hl += (i.getPopulation() * tmp);
            }
            // std::cout << "Happiness level = " << hl;
            // std::cout << std::endl;
            if (hl > bestHLsoFar) {
                bestHLsoFar = hl;
                bestCapitalsSoFar.clear();
                bestCapitalsSoFar.push_back(it->getName());
                bestCapitalsSoFar.push_back(jt->getName());
            }
        }
    }
    std::cout << std::endl;
    std::cout << "The best capitals would be ";
    for (auto i : bestCapitalsSoFar) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Happiness level = " << bestHLsoFar;
    std::cout << std::endl;
    std::cout << "Population = " << getPopulationOfTheWholeVector(vec);
    std::cout << std::endl;
    std::cout << "Percentage = "
              << static_cast<double>(10.0 * bestHLsoFar) /
                     getPopulationOfTheWholeVector(vec)
              << "%";
    std::cout << std::endl;

    return bestCapitalsSoFar;
}

std::vector<unsigned> generateRandomVectorWithoutRepetition(unsigned floor,
                                                            unsigned ceil,
                                                            unsigned size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(floor, ceil);

    std::vector<unsigned> vecOfRand;
    vecOfRand.reserve(size);
    vecOfRand.push_back(dis(gen));
    while (vecOfRand.size() < size) {
        unsigned tmp = dis(gen);
        if (std::find(vecOfRand.begin(), vecOfRand.end(), tmp) ==
            vecOfRand.end()) {
            vecOfRand.push_back(tmp);
        }
    }
    return vecOfRand;
}

std::vector<std::string> regionalizeUsingRandom(std::vector<City> vec,
                                                std::string numberOfRegions) {
    return regionalizeUsingRandom(vec, std::stoi(numberOfRegions));
}

std::vector<std::string> regionalizeUsingRandom(std::vector<City> vec,
                                                unsigned numberOfRegions) {
    std::cout << "regionalizeUsingRandom \n";
    std::cout << "number of regions = " << numberOfRegions << "\n";

    constexpr std::size_t tries{100};
    std::vector<std::string> bestCapitalsSoFar{};
    std::size_t bestHLsoFar{};
    auto sortedVec = sortVec(vec);

    for (std::size_t i{}; i < tries; ++i) {
        auto vecOfRand = generateRandomVectorWithoutRepetition(
            0, sortedVec.size()-1, numberOfRegions);
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
    std::cout << "The best capitals would be ";
    for (auto i : bestCapitalsSoFar) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Happiness level = " << bestHLsoFar;
    std::cout << std::endl;
    std::cout << "Population = " << getPopulationOfTheWholeVector(vec);
    std::cout << std::endl;
    std::cout << "Percentage = "
              << static_cast<double>(10.0 * bestHLsoFar) /
                     getPopulationOfTheWholeVector(vec)
              << "%";
    std::cout << std::endl;

    return bestCapitalsSoFar;
}

std::vector<City> sortVec(const std::vector<City> &vec) {
    auto sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end(),
         [](const City &lhs, const City &rhs) {
             return lhs.getPopulation() > rhs.getPopulation();
         });
    return sortedVec;
}

} // namespace VectorOfCities
