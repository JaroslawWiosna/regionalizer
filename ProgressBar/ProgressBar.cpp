/**
 * \class ProgressBar
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "ProgressBar.hpp"

void ProgressBar::printBar(unsigned percent) {
    std::cout << "                                       [";
    for (unsigned i = 0; i < width; ++i) {
        if (100 * i / width < percent) {
            std::cout << "#";
        } else {

            std::cout << "-";
        }
    }

    std::cout << "] " << percent << "%"
              << " ";
    std::cout << "\r";
    std::cout << " " << name << "\r";
    std::cout.flush();
}
