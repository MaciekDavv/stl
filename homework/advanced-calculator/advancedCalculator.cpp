#include "advancedCalculator.hpp"

//ErrorCode errorCode;


Operation add = [](const auto& a, const auto& b) { return a + b; };
Operation subtraction = [](const auto& a, const auto& b) { return a - b; };
Operation multiplication = [](const auto& a, const auto& b) { return a * b; };
Operation division = [](const auto& a, const auto& b) { return a / b; };
Operation modulo = [](const auto& a, const auto& b) { return std::fmod(a, b); };
Operation factorial = [](const auto& a, const auto& b) -> double { return std::tgamma(a); };
Operation power = [](const auto& a, const auto& b){ return std::pow(a, b); };
Operation element = [](const auto& a, const auto& b){ return std::pow(a, 1.0 / b); };

std::map<char, Operation> mymap = {
    {'+', add},
    {'-', subtraction},
    {'*', multiplication},
    {'/', division},
    {'%', modulo},
    {'!', factorial},
    {'^', power},
    {'$', element}
};

void TakeString::convertStringToDouble(std::string& str){
    std::istringstream packOut(str);
    packOut >> first >> beatween >> second;
}

void TakeString::checkIfStringIsCorect(std::string& str) {

}



ErrorCode process(std::string input, double* out) {
    TakeString conwert;

    conwert.convertStringToDouble(input);
    *out = mymap[conwert.beatween](conwert.first, conwert.second);
return ErrorCode::OK;
}

