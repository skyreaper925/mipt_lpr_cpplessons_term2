// Классическое возведение в степень
#include <iostream>
#include <cmath>
using namespace std;

int my_power(int base, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++) result *= base;
    return result;
}

int main()
{
    int base, power;
    cin >> base >> power;
    cout << (my_power(base, power)) << endl;
    return 0;
}
