#pragma once

#include <string>
#include <regex>
#include <map>
#include <functional>
#include <cmath>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>

using Operation = std::function<double(double, double)>;

extern std::map<char, Operation> mymap;

struct TakeString {

        double first = {0};
        char beatween = {' '};
        double second = {0};


        void convertStringToDouble(std::string& str);
        void checkIfStringIsCorect(std::string& str);
};

enum class ErrorCode{
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};


ErrorCode process(std::string input, double* out);


