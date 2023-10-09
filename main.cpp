#include <bits/stdc++.h>
using namespace std;
#include "calculator.cpp"
int main()
{
    calculator c;
    double result1 = c.calculate("2 + 3! * 4");
    if (result1 == 26.0)
    {
        std::cout << "Expression 1 is correct." << std::endl;
    }
    else
    {
        std::cout << "Expression 1 is incorrect." << std::endl;
    }
    double result2 = c.calculate("(1 + 2)! - 4");
    if (result2 == 2.0)
    {
        std::cout << "Expression 2 is correct." << std::endl;
    }
    else
    {
        std::cout << "Expression 2 is incorrect." << std::endl;
    }
    double result3 = c.calculate("5! / (3 + 2)");
    if (result3 == 24.0)
    {
        std::cout << "Expression 3 is correct." << std::endl;
    }
    else
    {
        std::cout << "Expression 3 is incorrect." << std::endl;
    }
    double result4 = c.calculate("4 + 6! - (2 * 3)");
    if (result4 == 718.0)
    {
        std::cout << "Expression 4 is correct." << std::endl;
    }
    else
    {
        std::cout << "Expression 4 is incorrect." << std::endl;
    }
    getchar();
    return 0;
}