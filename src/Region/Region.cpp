#include "../Region/Region.hpp"
#include "../City/City.hpp"
#include <random>
#include<algorithm>
#include<utility>

//struct EntryInLookupTableOfDistances {
//    std::shared_ptr<City> a;
//    std::shared_ptr<City> b;
//    double distance;
//};

//////

Region::Region(std::vector<std::shared_ptr<City>> vec) : cities{vec} {
    electCapital();
    fillLookupTableOfDistances();
    findTheLongestDistance();

//    std::cout << "address of cities " << &cities << "\n";
}

void Region::electCapital() {
    std::vector<std::shared_ptr<City>>::iterator maxPopulation = cities.begin();
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        if ((*it)->population() > (*maxPopulation)->population()) {
            maxPopulation = it;
        }
    }
    capital = maxPopulation;
}

void Region::fillLookupTableOfDistances() {
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        for (auto jt = it+1; jt != cities.end(); ++jt) {
            const double distance = (*it)->distanceTo(**jt);
            lookupTableOfDistances.emplace_back(EntryInLookupTableOfDistances{*it, *jt, distance});
        }
    }
}

void Region::findTheLongestDistance() {
//    double result{0};
//    auto max_distance = std::minmax_element(lookupTableOfDistances.begin(), lookupTableOfDistances.end(),
//                                            [](EntryInLookupTableOfDistances const& lhs, EntryInLookupTableOfDistances const& rhs){return lhs.distance < rhs.distance;} );

//    auto max_distance = std::max(lookupTableOfDistances, [](const EntryInLookupTableOfDistances& lhs, const EntryInLookupTableOfDistances& rhs){return lhs.distance < rhs.distance;});
//    longestDistance = max_distance->distance;

    longestDistance = 0;
    for (auto it = lookupTableOfDistances.begin(); it != lookupTableOfDistances.end(); ++it) {
        if (it->distance > longestDistance) {
            longestDistance = it->distance;
            extremePoint1 = it->a;
            extremePoint2 = it->b;
        }
    }
}

std::string Region::capitalName() const{
    return (*capital)->name();
}

void Region::printLookupTableOfDistances() const {
    for (const auto& item : lookupTableOfDistances) {
        std::cout << item.a->name() << " " << item.b->name() << " " << item.distance << "\n";
    }
    std::cout << "\n";
}

double Region::getLongestDistance() const{
    return longestDistance;
}

std::vector<Region> Region::makeSubregions(unsigned numberOfSubregions) const {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0, cities.size()-1);

    if (numberOfSubregions > cities.size()) {
        throw;
    }
////old approach
/*
    std::vector<std::shared_ptr<City>> newCenters;
    while (newCenters.size() < numberOfSubregions) {
        const int randomInt = uni(rng);
        const std::shared_ptr<City>& ref = cities.at(randomInt);
        std::shared_ptr<City> candidate(ref);
        if (std::find(newCenters.begin(), newCenters.end(), candidate) == newCenters.end()) {
            newCenters.push_back(candidate);
        }
    }

    for (const auto& item : newCenters) {
        std::cout << item->name() << "\n";
    }
*/
///end of old approach

    std::vector<Subregion> subregions;
    while (subregions.size() < numberOfSubregions) {
        const int randomInt = uni(rng);
        const std::shared_ptr<City>& ref = cities.at(randomInt);
        std::shared_ptr<City> candidate(ref);
        if (std::find_if(subregions.begin(), subregions.end(), [&candidate](const auto& elem){return (elem.capital == candidate);}) == subregions.end()) {
            subregions.push_back(Subregion{candidate});
        }
    }
    for (const auto& item : subregions) {
        std::cout << item.capital->name() << "\n";
    }
    for (const auto& city : cities) {
        std::vector<std::pair<std::shared_ptr<City>,double>> distanceToEachCapital;
        for(const auto& item : subregions) {
            distanceToEachCapital.push_back(std::make_pair(item.capital, city->distanceTo(*(item.capital))));
        }
        // now find the closest capital
        std::shared_ptr<City> closestCapital;
        double distanceToTheClosestCapital{1000000};
        for(const auto& item : distanceToEachCapital) {
            if (item.second < distanceToTheClosestCapital) {
                distanceToTheClosestCapital = item.second;
                closestCapital = item.first;
            }
        }
    }

    //

//    std::vector<std::vector<std::shared_ptr<City>>> newRegions;




    std::vector<std::shared_ptr<City>> first;
    std::vector<std::shared_ptr<City>> second;

    first.push_back(*capital);

    for (auto it = cities.begin(); it != cities.end(); ++it) {
        if (it != capital) {
            second.push_back(*it);
        }
    }

    std::vector<Region> result;
    result.push_back(Region{first});
    result.push_back(Region{second});
    return result;
}

void Region::printInfo() {
    std::cout << "The capital is " << capitalName() << "\n";
    std::cout << "The longest distance is " << getLongestDistance() << " km"
              << ", between " << (extremePoint1)->name() << " and " << (extremePoint2)->name() << "\n";
    std::cout << "This region has " << cities.size() << " cities:" << "\n";
    for (const auto& city : cities) {
    std::cout << "" << city->name() << ", ";
    }
    std::cout << "\n";
}
