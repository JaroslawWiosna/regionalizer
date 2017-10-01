#include "FlagParser.hpp"
#include "DatabaseReader.hpp"
#include "Gnuplot.hpp"

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
    
    for (City& i : vec) {
	//std::size_t farthestDistanceSoFar{};
	double farthestDistanceSoFar{};
        for (City j : vec) {
	    //std::size_t tmp = i.distanceFrom(j);
	    double tmp = i.distanceFrom(j);
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
    // Part 4 - start - by brute force check which city would be 
    // the best capital. We have only one region. 
    // This part is just for testing "happiness level" concept
    // "Happiness level" - value from 0 to 10.
    // 10 is the best, we have 10 when we are the capital, because the
    // distance to capital is equal to zero.
    // 0 is when the capital is the farthest city.
    // Formula: HL = 10 - ((distanceFrom(capital) / distanceToTheFarthest)*10)
    
    for (City i : vec) {
        std::cout << "The capital is " << i.getName();
        std::cout << std::endl;
	std::size_t hl{}; // happiness level
        for (City j : vec) {
		
	    std::size_t tmp = (10.0 - ((static_cast<double>(j.distanceFrom(i)) / 
                    static_cast<double>(j.getDistanceToTheFarthest()))*10.0));
	    hl += (j.getPopulation() * tmp);
		    
		/*
            hl += ( j.getPopulation() * 
                (0.0 + ((static_cast<double>(j.distanceFrom(i)) / 
                    static_cast<double>(j.getDistanceToTheFarthest()))*10.0)) );
		    */
	}
	std::cout << "Happiness level = " << hl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    // Part <last> - start - save to gnuplot.
    Gnuplot::saveDummyPlot();

    return 0;
}    
