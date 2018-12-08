#include "City/City.hpp"
#include "Latitude/Latitude.hpp"
#include "Region/Region.hpp"
#include "cities.hpp"
#include "KMeans/KMeans.hpp"
#include <algorithm>
#include <memory>
#include <vector>

#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define _(STRING) gettext(STRING)

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

  std::cout << "Number of subregions: " << subregions.size() << "\n";

  for (auto subregion : subregions) {
      std::cout << "===============\n";
      subregion.printInfo();
  }
  return 0;
}
