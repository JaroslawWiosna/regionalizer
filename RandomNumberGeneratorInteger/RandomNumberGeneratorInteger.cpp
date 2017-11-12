/**
 * \class RandomNumberGeneratorInteger
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "RandomNumberGeneratorInteger.hpp"

std::vector<unsigned>
RandomNumberGeneratorInteger::generateRandomVectorWithoutRepetition(
    unsigned size) {
    std::vector<unsigned> vecOfRand;
    vecOfRand.reserve(size);
    vecOfRand.push_back(dis(RandomNumberGenerator::gen));
    while (vecOfRand.size() < size) {
        unsigned tmp = dis(RandomNumberGenerator::gen);
        if (std::find(vecOfRand.begin(), vecOfRand.end(), tmp) ==
            vecOfRand.end()) {
            vecOfRand.push_back(tmp);
        }
    }
    return vecOfRand;
}
