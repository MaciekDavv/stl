#include "arithmeticAverage.hpp"

double ArithmeticAverage(const std::vector<int>& fir, const std::vector<int>& sec) {
    double lhs = std::accumulate(fir.cbegin(), fir.cend(), 0);
    double rhs = std::accumulate(sec.cbegin(), sec.cend(), 0);
    return (lhs + rhs) / (fir.size() + sec.size());
}

double Distance(const std::vector<int>& fir, const std::vector<int>& sec) {
    std::vector<int> temp;
    auto lamb = [](const auto& a, const auto& b){ return std::pow((a - b), 2); };
    std::transform(fir.cbegin(), fir.cend(), sec.begin(), std::back_inserter(temp), lamb);
    double result = std::accumulate(temp.begin(), temp.end(), 0);
    return std::sqrt(result);
}
