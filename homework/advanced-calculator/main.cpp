#include "advancedCalculator.hpp"

int main() {
    std::string Input{""};
    double exit = {0};
    double* point = &exit;

    std::cout << "Podaj wyrazenie matematyczne jakie chcesz obliczyc , albo q by wyjsc: " << '\n';

    while (true) {
        std::getline(std::cin, Input);
        if (Input == "q") {
            break;
        }
        *point = 0;
        process(Input, point);
        std::cout << Input << " = " << *point << '\n';
    }
    point = nullptr;
    return 0;
}
