// power
#include <iostream>
#include <algorithm>

using namespace std;


long long pow_rec(long long base, unsigned pow, long long accum = 1ll)
{
    if (0 == pow) return accum;
    return pow_rec(base, pow - 1, accum * base);
}


int main()
{
    long long base, power;
    cin >> base >> power;
    cout << pow_rec(base, power) << endl;
    return 0;
}