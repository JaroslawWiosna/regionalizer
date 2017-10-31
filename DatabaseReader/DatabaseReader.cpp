/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "DatabaseReader.hpp"

namespace DatabaseReader {

std::vector<City> readCitiesFromFile(const fs::path& databaseFile) {
    std::vector<City> vecOfCities;
    std::ifstream ifs;
    ifs.open(databaseFile, std::ifstream::in);
    std::string line{};

    while (std::getline(ifs, line)) {
        if (line[0] == '#') {
            continue;
        }
        std::vector<std::string> params;
        size_t pos;
        while ((pos = line.find(" ")) != std::string::npos) {
            line.replace(line.begin() + pos, line.begin() + pos + 1, "");
        }
        split(line, "|", params);

        City city(params[0], params[1], params[2], params[3], params[4]);
        vecOfCities.push_back(city);
    }

    return vecOfCities;
}

void split(std::string str, std::string splitBy,
           std::vector<std::string> &tokens) {
    tokens.push_back(str);
    std::size_t splitAt;
    std::size_t splitLen = splitBy.size();
    std::string frag;
    while (true) {
        frag = tokens.back();
        splitAt = frag.find(splitBy);
        if (splitAt == std::string::npos) {
            break;
        }
        tokens.back() = frag.substr(0, splitAt);
        tokens.push_back(frag.substr(splitAt + splitLen,
                                     frag.size() - (splitAt + splitLen)));
    }
}

} // namespace DatabaseReader
