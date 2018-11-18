#include <memory>
#include <vector>
#include <string>

class City;

class Region {
public:
    explicit Region(const std::vector<std::shared_ptr<City>>& vec);

    std::string capitalName() const;
    double getLongestDistance() const;

    std::vector<Region> makeSubregions(int number) const;
    void printInfo();

private:
    void electCapital();
    void findTheLongestDistance();

    std::vector<std::shared_ptr<City>> cities;
    std::vector<std::shared_ptr<City>>::iterator capital;
    double longestDistance;
    std::vector<std::shared_ptr<City>>::iterator extremePoint1;
    std::vector<std::shared_ptr<City>>::iterator extremePoint2;
};
