/**
 * \class RandomNumberGenerator
 * @file RandomNumberGenerator.hpp
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef RANDOMNUMBERGENERATOR_HPP
#define RANDOMNUMBERGENERATOR_HPP

#include <random>

class RandomNumberGenerator
{
  public:
    /**
     */
    explicit RandomNumberGenerator() : rd{}, gen{rd()} {
    }

  protected:
    std::random_device rd;
    std::mt19937 gen;
};

#endif // RANDOMNUMBERGENERATOR_HPP
