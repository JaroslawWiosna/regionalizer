#pragma once
#include <vector>
#include <memory>
class City;

void KMeans(const std::vector<std::shared_ptr<City>>& vec, int number);
