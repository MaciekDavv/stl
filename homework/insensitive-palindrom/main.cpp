#include <iostream>
#include <string>
#include <algorithm>

#include "palindrom.hpp"

int main()
{
    const std::string forPalindrom = {"AlA#"};
    
    auto check = is_palindrome(forPalindrom);
    std::cout << check << '\n';
    
    return 0;
}
