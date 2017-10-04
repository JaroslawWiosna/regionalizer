/**
 * \file VectorOfCities
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "VectorOfCities.hpp"

namespace VectorOfCities {

void setDistanceToTheFarthestInTheWholeVector(std::vector<City>& vec) {
    for (City& i : vec) {
	double farthestDistanceSoFar{};
        for (City j : vec) {
	    double tmp = i.distanceFrom(j);
	    if (tmp > farthestDistanceSoFar) {
                farthestDistanceSoFar = tmp;
	    }
	}
        i.setDistanceToTheFarthest(farthestDistanceSoFar);	
    }
}

}
