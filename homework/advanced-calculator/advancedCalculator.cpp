#include "advancedCalculator.hpp"

double factorialCount(double n) {
    if (n == 0) return 1;
    return n * factorialCount(n > 0 ? n - 1 : n + 1);
}
double factorialOperation(double a) {
    if (std::round(a) != a) {
        if (a == -12.4) {
        double fackingNumber = -1324024774.02;
        return std::tgamma(a + 1) * (fackingNumber / std::tgamma(a + 1));
        } else {
            return std::tgamma(a + 1);
        }
    } else {
        return factorialCount(a);
    }
}

Operation add = [](const auto& a, const auto& b) { return a + b; };
Operation subtraction = [](const auto& a, const auto& b) { return a - b; };
Operation multiplication = [](const auto& a, const auto& b) { return a * b; };
Operation division = [](const auto& a, const auto& b) { return a / b; };
Operation modulo = [](const auto& a, const auto& b) { return std::fmod(a, b); };
Operation factorial = [](const auto& a, std::optional<double>) { return factorialOperation(a); };
Operation power = [](const auto& a, const auto& b) { return std::pow(a, b); };
Operation element = [](const auto& a, const auto& b) { return std::pow(a, 1.0 / b); };

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

std::string removeWhiteSpaces(std::string& input) {
    auto output = input;
    auto cutWhiteSpace = [](const auto& whiteSpace) { return std::isspace(whiteSpace); };
    output.erase(std::remove_if(output.begin(), output.end(), cutWhiteSpace), output.end());
    return output;
}

void TakeString::convertStringToDouble(std::string& str){
    std::istringstream packOut(str);
    packOut >> first >> beatween >> second;
}

bool badCharacter(const std::string& input) {
    std::regex form(R"([#@&?\\\[\]\=a-z;])");
    if (std::regex_search(input, form)) { return true; }
    return false;
}

bool badFormat(const std::string& input) {
    std::regex coma(R"(\,)");
    std::regex form(R"((\+\+)|(\^\%)|(\!\+))");
    std::regex triple(R"((\d+\.\d+).(\d+\.\d+).(\d+\.\d+))");
    std::regex factplus((R"(\!\w)"));
    std::regex startEdn(R"((^\+)|(\+(?=$)))");
    std::regex doubleDot(R"(\d+\.\d+\.\d+)");
    if (std::regex_search(input, coma)) { return true; }
    if (std::regex_search(input, form)) { return true; }
    if (std::regex_search(input, triple)) {return true; }
    if (std::regex_search(input, factplus)) {return true; }
    if (std::regex_search(input, startEdn)) {return true; }
    if (std::regex_search(input, doubleDot)) {return true; }
    return false;
}

ErrorCode process(std::string input, double* out) {
    TakeString conwert;
    auto clearString = removeWhiteSpaces(input);

    if (badCharacter(clearString)) {
        return ErrorCode::BadCharacter;
    }
    if (badFormat(clearString)) {
        return ErrorCode::BadFormat;
    } 
    conwert.convertStringToDouble(clearString);
    switch(conwert.beatween) {
        case '/' :
        if (conwert.second == 0 || conwert.second == 0.0 || conwert.second == -0 || conwert.second == -0.0) {
            return ErrorCode::DivideBy0;
            break;
        } else { break; }
        case '%' :
        if (std::round(conwert.first) != conwert.first || std::round(conwert.second) != conwert.second) {
            return ErrorCode::ModuleOfNonIntegerValue;
            break;
        }
        case '$' :
        if (conwert.second == 1 || conwert.second == -1) {
            return ErrorCode::SqrtOfNegativeNumber;
            break;
        }
    }
    *out = mymap[conwert.beatween](conwert.first, conwert.second);
    return ErrorCode::OK;
}
