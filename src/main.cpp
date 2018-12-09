#include "City/City.hpp"
#include "Latitude/Latitude.hpp"
#include "Region/Region.hpp"
#include "cities.hpp"
#include "KMeans/KMeans.hpp"
#include "gettext.hpp"
#include <algorithm>
#include <memory>
#include <vector>

#include <string.h>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");
  bindtextdomain("hello", "./locale");
  textdomain("hello");

  bool doDemo{false};
  for (int i = 1; i < argc; ++i) {
      if (strcmp(argv[i], "--demo") == 0) {
          doDemo = true;
          break;
      }
  }

  if (!doDemo) {
      std::cout << "./regionalizer --demo -N [number] \t to run demo\n";
      return -1;
  }

  int numberOfSubregions = 0;
  for (int i = 1; i < argc-1; ++i) {
      if ((strcmp(argv[i], "--number") == 0) || (strcmp(argv[i], "-N") == 0 ) ) {
          numberOfSubregions = std::stoi(argv[i+1]);
          break;
      }
  }
  if (0 == numberOfSubregions) {
      std::cout << "./regionalizer --demo -N [number] \t to run demo\n";
      return -1;
  }


  printf("%s\n", _("This is regionalizer"));

  Region polska{v};
  std::cout << polska.capitalName() << "\n";

  if (numberOfSubregions <= 1 || numberOfSubregions >= 10) {
      numberOfSubregions = 4;
  }
  auto subregions = polska.makeSubregions(numberOfSubregions);

  const char* numberOfSubregionsLine = _("Number of subregions: %s");
  char buf[1024];
  sprintf(buf, numberOfSubregionsLine, std::to_string(subregions.size()).c_str());
  std::string numberOfSubregionsLineAsString{buf};
  std::cout << numberOfSubregionsLineAsString << "\n";

  for (auto subregion : subregions) {
      std::cout << "===============\n";
      subregion.printInfo();
  }
  return 0;
}
