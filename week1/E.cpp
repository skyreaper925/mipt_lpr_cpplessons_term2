// Рекурсивное возведение в степень
#include <iostream>
#include <cmath>
using namespace std;

int recursive_power(int base, int power)
{
    if (!(power)) return 1;
    return base * recursive_power(base, power - 1);
}

int main()
{
    int base, power;
    cin >> base >> power;
    cout << (recursive_power(base, power)) << endl;
    return 0;
}
