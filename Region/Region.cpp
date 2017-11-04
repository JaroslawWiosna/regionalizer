/**
 * \class Region
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "Region.hpp"

std::string Region::getName() const {
    return name;
}

void Region::regionalize(std::string numberOfRegions) {
    VectorOfCities::regionalize(vec, std::stoi(numberOfRegions));
}

void Region::regionalize(unsigned numberOfRegions) {
    VectorOfCities::regionalize(vec, numberOfRegions);
}

void Region::plotPopulationAnimated() {
    GnuplotHandler::plotPopulationAnimated(vec);
}
