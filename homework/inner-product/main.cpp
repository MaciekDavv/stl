#include <iostream>
#include "arithmeticAverage.hpp"

int main() {
    std::vector<int> vecA = {1, 2, 3, 4};
    std::vector<int> vecAA = {1, 2, 3, 4};

    std::vector<int> vecB = {7, 4, 3};
    std::vector<int> vecBB = {17, 6, 2};

    std::cout << "ArithmeticAberage: " << ArithmeticAverage(vecA, vecAA) << "\n";
    std::cout << "Distance: " << Distance(vecB, vecBB) << "\n";

    return 0;
}
