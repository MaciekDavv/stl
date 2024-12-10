#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <optional>
#include <regex>
#include <sstream>
#include <string>

using Operation = std::function<double(double, double)>;
extern std::map<char, Operation> mymap;

struct TakeString {
    double first = {0};
    char beatween = {' '};
    double second = {0};
    void convertStringToDouble(std::string& str);
};

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

std::string removeWhiteSpaces(std::string& input);
bool badCharacter(const std::string& input);
bool badFormat(const std::string& input);
double factorialCount(double n);
double factorialOperation(double a);

ErrorCode process(std::string input, double* out);
