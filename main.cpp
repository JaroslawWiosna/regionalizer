#include "FlagParser.hpp"
#include "DatabaseReader.hpp"

int main(int argc, char *argv[]) {
    // Part 1 - start - parse argv and get databaseFile
    FlagParser parser(argc, argv);
    parser.printFlags();
    auto flags = parser.getFlags();

    if (!flags["-list"].empty()) {
        std::cout << "Great! " << flags["-list"] << " is being processed";
	std::cout << std::endl;
    } else {
	std::cout << "No list specified!";
	std::cout << std::endl;
	std::cout << "Aborting....";
	std::cout << std::endl;
	return -1;
    }

    std::string databaseFile{flags["-list"]};
    // Part 1 - end
    // Part 2 - start - create vector of Cities based on databaseFile
    auto vec = DatabaseReader::readCitiesFromFile(databaseFile);

    for (City i : vec) {
        std::cout << i.getAllFields();
        std::cout << std::endl;
    }

    // Part 2 - end
    // Part 3 - start - calculate distance from one city to the farthest
    
    for (City i : vec) {
	std::size_t farthestDistanceSoFar{};
        for (City j : vec) {
	    std::size_t tmp = i.distanceFrom(j);
	    if (tmp > farthestDistanceSoFar) {
                farthestDistanceSoFar = tmp;
	    }
	}
        i.setDistanceToTheFarthest(farthestDistanceSoFar);	
    }

    for (City i : vec) {
        std::cout << i.getAllFields();
        std::cout << std::endl;
    }
    // Part 3 - end

    return 0;
}    
