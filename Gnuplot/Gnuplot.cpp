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
    std::ofstream dummyPlot;
    dummyPlot.open("dummyPlot.gnu");

    dummyPlot << "set terminal pngcairo  transparent enhanced font \"arial,10\" fontscale 1.0 size 500, 350";
    dummyPlot << std::endl;
    dummyPlot << "set output 'dummyPlot.png'";
    dummyPlot << std::endl;
    dummyPlot << "set key inside left top vertical Right noreverse enhanced autotitles box linetype -1 linewidth 1.000";
    dummyPlot << std::endl;
    dummyPlot << "set samples 50, 50";
    dummyPlot << std::endl;
    dummyPlot << "plot [-10:10] sin(x),atan(x),cos(atan(x))";
    dummyPlot << std::endl;

    dummyPlot.close();
    system( "gnuplot dummyPlot.gnu" );
    system( "rm -f dummyPlot.gnu" );
}

bool isGnuplotInstalledOnHost() {
    return ( 0 == system("gnuplot --version") ? true : false );
}

}

