// Поиск НОД
#include <iostream>
#include <cmath>
using namespace std;

int max (int a, int b)
{
    if (a >= b) {return a;}
    else {return b;}
}

int min (int a, int b)
{
    if (a >= b) {return b;}
    else {return a;}
}

int main()
{
    int a, b, a1, b1, m;
    cin >> a >> b;
    while (a > 0 and b > 0)
        // {
        //     a1 = max(a, b); b1 = min(a, b);
        //     a = max(a1 - b1, b1); b = min(a1 - b1, b1);
        // }
    {
        a1 = max(a, b); b1 = min(a, b);
        a = max(a1 % b1, b1); b = min(a1 % b1, b1);
    }

    cout << max(a, b) << endl;
}
