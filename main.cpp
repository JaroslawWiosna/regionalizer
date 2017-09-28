#include "FlagParser.hpp"

int main(int argc, char *argv[]) {
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

    return 0;
}    
