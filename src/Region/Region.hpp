#include <memory>
#include <vector>
#include <string>

class City;
//struct EntryInLookupTableOfDistances;

struct EntryInLookupTableOfDistances {
    std::shared_ptr<City> a;
    std::shared_ptr<City> b;
    double distance;
};


class Region {
public:
    explicit Region(std::vector<std::shared_ptr<City>> vec);

    std::string capitalName() const;
    void printLookupTableOfDistances() const;
    double getLongestDistance() const;

    std::vector<Region> makeSubregions(unsigned) const;
    void printInfo();

private:
    void electCapital();
    void fillLookupTableOfDistances();
    void findTheLongestDistance();

    std::vector<std::shared_ptr<City>> cities;
    std::vector<std::shared_ptr<City>>::iterator capital;
    std::vector<EntryInLookupTableOfDistances> lookupTableOfDistances;
    double longestDistance;
    std::shared_ptr<City> extremePoint1;
    std::shared_ptr<City> extremePoint2;
};

struct Subregion {
    explicit Subregion(std::shared_ptr<City> capital) : capital{capital}, cities{} {}
    explicit Subregion(std::shared_ptr<City> capital, std::vector<std::shared_ptr<City>> cities) : capital{capital}, cities{cities} {}
    std::shared_ptr<City> capital;
    std::vector<std::shared_ptr<City>> cities;
};
