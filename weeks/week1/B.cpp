// Количество нулей на конце
#include <iostream>
#include <cmath>
using namespace std;

int number_of_entrances (int n, int k=5)
{
    int numberk = 0;
    while (n-1)
    {
        if (!n) return 0;

        if ((n % k) == 0)
        {
            numberk++;
            n /= k;
        }

        else break;
    }

    return numberk;
}


int main()
{
    int n; int sum = 0;
    cin >> n;
    for (int i = 0; i <=n; i++)
    {
        sum += number_of_entrances(i);
    }

    cout << sum << endl;
    return 0;
}

