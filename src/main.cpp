#include "City/City.hpp"
#include "Latitude/Latitude.hpp"
#include "Region/Region.hpp"
#include <algorithm>
#include <memory>
#include <vector>

int main() {

  {
    Latitude lat{50};
    std::cout << lat.print() << "\n";

    auto krakow = std::make_shared<City>("Kraków", 50, 20, 760000);
    krakow->print();

    auto lodz = std::make_shared<City>("Łódź", 51.75, 19.5, 687000);
    lodz->print();

    auto distance = krakow->distanceTo(*lodz);
    std::cout << distance << "\n";
  }

  ///////////////////

  std::vector<std::shared_ptr<City>> v{
      {std::make_shared<City>("Szczecin", 53.5, 14.5, 400000)},
      {std::make_shared<City>("Łódź", 51.75, 19.5, 687000)},
      {std::make_shared<City>("Warszawa", 52.20, 21, 1760000)},
      {std::make_shared<City>("Kraków", 50, 20, 760000)},
      {std::make_shared<City>("Poznań", 52.4, 17, 540000)}};

  for (const auto& item : v) {
      std::cout << item << "\t" << item->name() << " \tuse_count() = " << item.use_count() << "\n";
  }
  std::cout << "\n";

  {
    auto iter = std::find_if(std::begin(v), std::end(v), [](const auto &elem) {
      return (elem->name() == "Łódź");
    });
  }

  ///////////////////////////////

  std::cout << "address of v " << &v << "\n";

  ///////////////////////////////

  Region polska{v};
  std::cout << polska.capitalName() << "\n";
  polska.printInfo();

  std::cout << "TUTUTUsize of v after it was passed to Region's ctor: " << v.size() << " \n";
  for (const auto& item: v) {
      std::cout << item << "\t" << item->name() << " \tuse_count() = " << item.use_count() << "\n";
  }
  std::cout << "\n";
/*
  auto subregions = polska.makeSubregions(2);

  for (auto subregion : subregions) {
//      subregion.printInfo();
  }
  subregions.at(1).printInfo();
*/
  return 0;
}
