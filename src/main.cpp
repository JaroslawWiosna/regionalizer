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

#define _(STRING) gettext(STRING)

int main() {
setlocale(LC_ALL, "");
bindtextdomain("hello", "./locale");
textdomain("hello");
  printf("%s\n", _("This is regionalizer"));

  Region polska{v};
  std::cout << polska.capitalName() << "\n";


  auto subregions = polska.makeSubregions(4);

  std::cout << "Number of subregions: " << subregions.size() << "\n";

  for (auto subregion : subregions) {
      std::cout << "===============\n";
      subregion.printInfo();
  }
  return 0;
}
