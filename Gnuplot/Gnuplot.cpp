/**
 * \class Gnuplot
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "Gnuplot.hpp"

namespace Gnuplot {

void saveDummyPlot() {
    std::cout << "saveDummyPlot\n";
}

bool isGnuplotInstalledOnHost() {
    return ( 0 == system("gnuplot --version") ? true : false );
}

}

