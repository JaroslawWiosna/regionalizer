/**
 * \class RandomNumberGeneratorInteger
 * @file RandomNumberGeneratorInteger.hpp
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef RANDOMNUMBERGENERATORINTEGER_HPP
#define RANDOMNUMBERGENERATORINTEGER_HPP

#include "RandomNumberGenerator.hpp"
#include <algorithm>
#include <vector>

class RandomNumberGeneratorInteger : public RandomNumberGenerator
{
  public:
    /**
     */
    explicit RandomNumberGeneratorInteger(unsigned floor, unsigned ceil)
        : RandomNumberGenerator{}, dis{static_cast<int>(floor),
                                       static_cast<int>(ceil)} {
    }

    std::vector<unsigned> generateRandomVectorWithoutRepetition(unsigned size);

  private:
    std::uniform_int_distribution<> dis;
};

#endif // RANDOMNUMBERGENERATORINTEGER_HPP
