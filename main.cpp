/**
 * \class main
 * @file main.cpp
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "FlagParser.hpp"
#include "Region.hpp"
#include "help.txt.hpp"

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[]) {
    FlagParser parser(argc, argv);
    parser.printFlags();
    auto flags = parser.getFlags();

    setlocale(LC_ALL, "");
    bindtextdomain("regionalizer", "/usr/share/locale");
    textdomain("regionalizer");

    if (!parser.hasKey("--help")) {
        std::cout << _("Help not found, so moving on...");
        std::cout << std::endl;
    } else {
        std::cout << _("Help found, so I am about to print help...");
        std::cout << std::endl;
        std::cout << ___help_txt;
        std::cout << _("Aborting....");
        std::cout << std::endl;
        return -1;
    }
    if (!flags["--list"].empty()) {
        char buf[100];
        std::sprintf(buf, _("Great! %s is being processed"),
                     flags["--list"].c_str());
        std::cout << buf;
        std::cout << std::endl;
    } else {
        std::cout << _("No list specified!");
        std::cout << std::endl;
        std::cout << _("Aborting....");
        std::cout << std::endl;
        return -1;
    }

    std::string databaseFile{flags["--list"]};
    Region region{databaseFile};

    if (parser.hasKey("-N")) {
        auto subregions = region.regionalize(flags["-N"]);
        std::cout << "The capitals are:" << std::endl;
        for (const auto &subregion : subregions) {
            std::cout << subregion.getCapital() << std::endl;
        }
        std::cout << "Happiness level = ";
        std::size_t HL{};
        for (const auto &subregion : subregions) {
            HL += subregion.getHappinessLevel();
        }
        std::cout << std::endl;
    }

    if (parser.hasKey("--gif")) {
        region.plotPopulationAnimated();
    }

    if (parser.hasKey("--histogram") || parser.hasKey("--hist")) {
        region.plotHistogram();
    }

    return 0;
}
