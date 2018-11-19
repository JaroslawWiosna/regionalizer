#include "City/City.hpp"
#include "Latitude/Latitude.hpp"
#include "Region/Region.hpp"
#include "cities.hpp"
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
  polska.printInfo();

//  polska.printLookupTableOfDistances();

  v.clear();
//  auto subregions = polska.makeSubregions(2);

//  for (auto subregion : subregions) {
//      subregion.printInfo();
//  }
//  subregions.at(1).printInfo();

  return 0;
}
