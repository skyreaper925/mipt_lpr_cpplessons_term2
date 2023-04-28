// Проверка на простоту
#include <iostream>
#include <cmath>
using namespace std;

bool is_prime (int n)
{
    if (n == 1 or n == 4) {return false;}
    if (n == 2) {return true;}
    for (int i = 3; i < (sqrt(n) + 1); i+=2)
    {
        if (n % i == 0) {return false;}
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    if (is_prime(n)) {cout << "Yes";}
    else {cout << "No";}
    return 0;
}
