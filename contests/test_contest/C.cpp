// least common multiple
#include <iostream>

using namespace std;

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    unsigned long long a_copy = a, b_copy = b;
    while (a_copy and b_copy)
    {
        if (a_copy >= b_copy)
            a_copy %= b_copy;
        else
            b_copy %= a_copy;
    }
    return a / (a_copy + b_copy) * b;
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << lcm(a, b) << endl;
    return 0;
}