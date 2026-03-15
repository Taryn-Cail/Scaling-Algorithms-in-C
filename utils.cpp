#include "utils.h"
#include <random>

std::vector<int> generateRandomArray(int size)
{
    std::vector<int> arr(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, size);

    for (int &x : arr)
        x = dist(gen);

    return arr;
}