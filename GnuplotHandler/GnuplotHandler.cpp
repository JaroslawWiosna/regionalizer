/**
 * @file GnuplotHandler
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "GnuplotHandler.hpp"

namespace GnuplotHandler {

void saveDummyPlot() {
    std::cout << "saveDummyPlot\n";
    std::ofstream script;
    script.open("script.gnu");

    script << "set terminal pngcairo  transparent enhanced font \"arial,10\" fontscale 1.0 size 500, 350";
    script << std::endl;
    script << "set output 'script.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced autotitles box linetype -1 linewidth 1.000";
    script << std::endl;
    script << "set samples 50, 50";
    script << std::endl;
    script << "plot [-10:10] sin(x),atan(x),cos(atan(x))";
    script << std::endl;

    script.close();
    system( "gnuplot script.gnu" );
    system( "rm -f script.gnu" );
}

bool isGnuplotInstalledOnHost() {
    return ( 0 == system("gnuplot --version &> /dev/null") ? true : false );
}

void plotHappinessLevelWhenWeHaveOnlyOneRegion(std::vector<City> vec) {
    std::ofstream data;
    data.open("HappinessLevel-onlyOneRegion.dat");
    for (const City& i : vec) {
        data << i.getLatitude();
	data << " ";
        data << i.getLongitude();
	data << " ";
	data << "345345345";
	data << std::endl;
    }
    data.close();

    std::ofstream script;
    script.open("HappinessLevel-onlyOneRegion.gnu");
    script << "set terminal pngcairo  transparent enhanced font \"arial,10\" fontscale 1.0 size 500, 350";
    script << std::endl;
    script << "set output 'HappinessLevel-onlyOneRegion.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced autotitles box linetype -1 linewidth 1.000";
    script << std::endl;
    script << "set title \"HL\"";
    script << std::endl;
    script << "splot 'HappinessLevel-onlyOneRegion.dat'";
    script << std::endl;
    script << "set output";
    script << std::endl;

    script.close();
    system( "gnuplot HappinessLevel-onlyOneRegion.gnu" );
    system( "rm -f HappinessLevel-onlyOneRegion.gnu" );
    system( "rm -f HappinessLevel-onlyOneRegion.dat" );
}    

void plotPopulation(const std::vector<City>& vec) {
    std::ofstream data;
    data.open("population.dat");

    auto sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end(), [](const City& lhs, 
            const City& rhs) {
        return lhs.getPopulation() < rhs.getPopulation();
    });
    for (const City& i : sortedVec) {
        data << i.getLongitude();
        data << " ";
        data << i.getLatitude();
        data << " ";
        data << i.getPopulation();
        data << std::endl;
    }
    data.close();

    std::ofstream script;
    script.open("population.gnu");
    script << "set terminal pngcairo  transparent enhanced font \"arial,10\" fontscale 1.0 size 2000, 1400";
    script << std::endl;
    script << "set output 'population.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced autotitles box linetype -1 linewidth 1.000";
    script << std::endl;
    script << "set title \"HL\"";
    script << std::endl;
    script << "set ylabel \"latitude\"";
    script << std::endl;
    script << "set xlabel \"longitude\"";
    script << std::endl;
    script << "set xrange [14 : 25] reverse nowriteback";
    script << std::endl;
    script << "set yrange [49 : 56] noreverse nowriteback";
    script << std::endl;
    script << "plot 'population.dat' with points palette pt 7 ps 5 ";
    script << std::endl;
    script << "set output";
    script << std::endl;

    script.close();
    system( "gnuplot population.gnu" );
//    system( "rm -f population.gnu" );
//    system( "rm -f population.dat" );
}

}

