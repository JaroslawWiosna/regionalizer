/**
 * \class ProgressBar
 * @file ProgressBar.hpp
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include <iostream>
#include <stdio.h>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

class ProgressBar
{
  public:
    explicit ProgressBar() : name{""} {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        width = w.ws_col - 50;
    }

    explicit ProgressBar(const std::string &name) : name{name} {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        width = w.ws_col - 50;
    }

    ~ProgressBar() {
        printBar(100);
        std::cout << std::endl;
    }
    void printBar(unsigned percent);

  private:
    unsigned width;
    std::string name;
};

#endif // PROGERSSBAR_HPP
