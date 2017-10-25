/**
 * @class GnuplotHandler
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef GNUPLOTHANDLER_HPP
#define GNUPLOTHANDLER_HPP

#include <fstream>
#include <iostream>
//#include <list>
//#include <cfloat> // FLT_MIN
//#include <cmath> // abs
#include <algorithm>
#include <string>
#include <vector>
//#include <memory>
//#include <utility>
//#include <type_traits>
#include "City.hpp"
#include <stdlib.h>

namespace GnuplotHandler {

void saveDummyPlot();
bool isGnuplotInstalledOnHost();
void plotHappinessLevelWhenWeHaveOnlyOneRegion(std::vector<City> vec);
void plotHappinessIndex(const std::vector<City> &vec,
                        std::vector<std::string> capitals);
void plotPopulation(const std::vector<City> &vec);
void plotPopulationAnimated(const std::vector<City> &vec);

} // namespace GnuplotHandler

#endif // GNUPLOTHANDLER_HPP
