#include "../Region/Region.hpp"
#include "../City/City.hpp"

//Region::Region(std::vector<std::shared_ptr<City>> vec) : cities{std::move(vec)} {
//Region::Region(std::vector<std::shared_ptr<City>>&& vec) : cities{vec} {
//Region::Region(std::vector<std::shared_ptr<City>>&& vec) : cities{vec} {
Region::Region(const std::vector<std::shared_ptr<City>>& vec) {
//Region::Region(std::vector<std::shared_ptr<City>> vec) {
    //cities.reserve(vec.size());
    for (const std::shared_ptr<City>& item : vec) {
        //cities.push_back(std::make_shared<City>(*item));

        //cities.push_back(item);
        std::shared_ptr<City> tmp(item);
        cities.push_back(tmp);

        std::cout << item << "\t" << item->name() << " \tuse_count() = " << item.use_count() << "\n";
    }

    electCapital();
    findTheLongestDistance();

    std::cout << "address of cities " << &cities << "\n";

    for (const std::shared_ptr<City>& item : cities) {
        std::cout << item << "\t" << item->name() << " \tuse_count() = " << item.use_count() << "\n";
    }
    std::cout << "\n";
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

void Region::findTheLongestDistance() {
    double result{0};
    for (auto it = cities.begin(); it != cities.end(); ++it) {
        for (auto jt = it+1; jt != cities.end(); ++jt) {
            double distance = (*it)->distanceTo(**jt);
            std::cout << "\t" << (*it)->name() << "-" << (*jt)->name() << "  \t" << distance << " \n";
            if (distance > result) {
                result = distance;
                extremePoint1 = it;
                extremePoint2 = jt;
            }
        }
    }
    longestDistance = result;
}

std::string Region::capitalName() const{
    return (*capital)->name();
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
              << ", between " << (*extremePoint1)->name() << " and " << (*extremePoint2)->name() << "\n";
    std::cout << "This region has " << cities.size() << " cities:" << "\n";
    for (const auto& city : cities) {
    std::cout << "\t" << city->name() << "\n";
    }
    std::cout << "\n";
}
