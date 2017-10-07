/**
 * \class Gnuplot
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef GNUPLOT_HPP
#define GNUPLOT_HPP

#include <iostream>
#include <fstream>
//#include <list>
//#include <cfloat> // FLT_MIN
//#include <cmath> // abs
//#include <algorithm>
#include <vector>
#include <string>
//#include <memory>
//#include <utility>
//#include <type_traits>
#include <stdlib.h>
#include "City.hpp"

namespace Gnuplot {

void saveDummyPlot();
bool isGnuplotInstalledOnHost();
void plotHappinessLevelWhenWeHaveOnlyOneRegion(std::vector<City> vec);

}

#endif // GNUPLOT_HPP

