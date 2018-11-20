#include "KMeans.hpp"
#include "../City/City.hpp"
#include <vector>
#include <memory>
#include <random>

void KMeans(std::vector<std::shared_ptr<City>> vec, int number) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(1, vec.size());



//    std::cout << uni(rng) << "\n";
//    std::cout << uni(rng) << "\n";
//    std::cout << uni(rng) << "\n";
//    std::cout << uni(rng) << "\n";
    std::cout << "KMeans end\n";
}
