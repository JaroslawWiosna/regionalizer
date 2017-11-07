/**
 * @class GnuplotHandler
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


    script << "set terminal pngcairo enhanced font \"arial,10\" fontscale 1.0 "
              "size 500, 350";
    script << std::endl;
    script << "set output 'script.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced "
              "autotitles box linetype -1 linewidth 1.000";
    script << std::endl;
    script << "set samples 50, 50";
    script << std::endl;
    script << "plot [-10:10] sin(x),atan(x),cos(atan(x))";
    script << std::endl;

    script.close();
    system("gnuplot script.gnu");
    system("rm -f script.gnu");
}

bool isGnuplotInstalledOnHost() {
    return (0 == system("gnuplot --version &> /dev/null") ? true : false);
}

void plotHappinessLevelWhenWeHaveOnlyOneRegion(std::vector<City> vec) {
    std::ofstream data;
    data.open("HappinessLevel-onlyOneRegion.dat");
    for (const City &i : vec) {
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
    script << "set terminal pngcairo enhanced font \"arial,10\" fontscale 1.0 "
              "size 500, 350";
    script << std::endl;
    script << "set output 'HappinessLevel-onlyOneRegion.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced "
              "autotitles box linetype -1 linewidth 1.000";
    script << std::endl;
    script << "set title \"HL\"";
    script << std::endl;
    script << "splot 'HappinessLevel-onlyOneRegion.dat'";
    script << std::endl;
    script << "set output";
    script << std::endl;

    script.close();
    system("gnuplot HappinessLevel-onlyOneRegion.gnu");
    system("rm -f HappinessLevel-onlyOneRegion.gnu");
    system("rm -f HappinessLevel-onlyOneRegion.dat");
}

void plotHappinessIndex(const std::vector<City> &vec,
                        std::vector<std::string> capitals) {
    std::ofstream data;
    data.open("hi.dat");
    for (const auto &i : vec) {
        double bestHISoFar{};
        for (const auto &j : capitals) {
            auto it =
                std::find_if(std::begin(vec), std::end(vec),
                             [&](City const &c) { return c.getName() == j; });
            std::size_t hi =
                10.0 -
                ((static_cast<double>(
                      i.distanceFrom(*it) /
                      static_cast<double>(i.getDistanceToTheFarthest())) *
                  10.0));
            if (hi > bestHISoFar) {
                bestHISoFar = hi;
            }
        }
        data << i.getLongitude();
        data << " ";
        data << i.getLatitude();
        data << " ";
        data << bestHISoFar;
        data << std::endl;
    }
    data.close();

    std::ofstream script;
    script.open("hi.gnu");
    script << "set terminal pngcairo enhanced font \"arial,10\" fontscale 1.0 "
              "size 2000, 1400";
    script << std::endl;
    script << "set output 'hi.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced "
              "autotitles box linetype -1 linewidth 1.000";
    script << std::endl;
    script << "set title \"Happiness Index - Number of regions =  ";
    script << capitals.size();
    script << "\"";
    script << std::endl;
    script << "set ylabel \"latitude\"";
    script << std::endl;
    script << "set xlabel \"longitude\"";
    script << std::endl;
    script << "set xrange [14 : 25] reverse nowriteback";
    script << std::endl;
    script << "set yrange [49 : 56] noreverse nowriteback";
    script << std::endl;
    script << "set cbrange [5: 10]";
    script << std::endl;
    script << "plot 'hi.dat' with points palette pt 7 ps 5 ";
    script << std::endl;
    script << "set output";
    script << std::endl;

    script.close();
    system("gnuplot hi.gnu");
    system("rm -f hi.gnu");
    system("rm -f hi.dat");
}

void plotPopulation(const std::vector<City> &vec) {
    std::ofstream data;
    data.open("population.dat");

    auto sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end(),
         [](const City &lhs, const City &rhs) {
             return lhs.getPopulation() < rhs.getPopulation();
         });
    for (const City &i : sortedVec) {
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
    script << "set terminal pngcairo enhanced font \"arial,10\" fontscale 1.0 "
              "size 2000, 1400";
    script << std::endl;
    script << "set output 'population.png'";
    script << std::endl;
    script << "set key inside left top vertical Right noreverse enhanced "
              "autotitles box linetype -1 linewidth 1.000";
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

    system("gnuplot population.gnu");
    //    system( "rm -f population.gnu" );
    //    system( "rm -f population.dat" );
}

void plotPopulationAnimated(const std::vector<City> &vec) {
    std::ofstream data;
    unsigned count{1};
    for (; count < vec.size(); count += (vec.size() / 20)) {
        data.open("population.dat");
        auto sortedVec = vec;
        sort(sortedVec.begin(), sortedVec.end(),
             [](const City &lhs, const City &rhs) {
                 return lhs.getPopulation() < rhs.getPopulation();
             });
        for (auto it = sortedVec.begin(); it != sortedVec.begin() + count;
             ++it) {
            data << it->getLongitude();
            data << " ";
            data << it->getLatitude();
            data << " ";
            data << it->getPopulation();
            data << std::endl;
        }
        data.close();

        std::ofstream script;
        script.open("population.gnu");
        script << "set terminal pngcairo enhanced font \"arial,10\" fontscale "
                  "1.0 size 2000, 1400";
        script << std::endl;
        script << "set output 'populationFrame";
        if (count < 10) {
            script << "000";
        } else if (count < 100) {
            script << "00";
        } else if (count < 1000) {
            script << "0";
        }
        script << count;
        script << ".png'";
        script << std::endl;
        script << "set key inside left top vertical Right noreverse enhanced "
                  "autotitles box linetype -1 linewidth 1.000";
        script << std::endl;
        script << "set title \"Population\"";
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
        system("gnuplot population.gnu");
        system("rm -f population.gnu");
        system("rm -f population.dat");
    }
    plotPopulation(vec);

    system("cp population.png populationFrame1000.png");
    system("cp population.png populationFrame1001.png");
    system("cp population.png populationFrame1002.png");
    system("cp population.png populationFrame1003.png");
    system("cp population.png populationFrame1004.png");

    system("rm -f populationAnimated.png");
    system("convert -delay 60 -loop 0 populationFrame*.png "
           "populationAnimated.gif");
    system("rm -f populationFrame*.png");
}


} // namespace GnuplotHandler
