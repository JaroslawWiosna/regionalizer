#include "../Region/Region.hpp"
#include "../City/City.hpp"

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

    std::cout << "address of cities " << &cities << "\n";
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

std::vector<Region> Region::makeSubregions(int number) const {
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
    std::cout << "\t" << city->name() << "\n";
    }
    std::cout << "\n";
}
