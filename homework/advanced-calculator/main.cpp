#include "advancedCalculator.hpp"

#include <memory>
#include <iostream>

int main() {
     std::string a = {"12 + 24"};
    // TakeString convert;
    // convert.convertStringToDouble(a);
    // std::cout << convert.first << " " << convert.beatween << " " << convert.second << "\n";
    // std::cout << "\n";
    // auto result = mymap[convert.beatween](convert.first, convert.second);
    // std::cout << result << '\n';

    double exit = {0};
    double* point = &exit;

    //auto point = std::make_shared<double>(0);
    auto proc = process(a, point);
    std::cout << "calculate = " << *point << "     Error Code: " <<  '\n'; 

    point = nullptr;
    return 0;
}