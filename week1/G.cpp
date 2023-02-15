// Характер массива
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n, our, previous, next, min = 0, max = 0;
    cin >> n >> previous >> our;
    for (int i = 1; i < n - 1; i++)
    {
        cin >> next;
        if ((our > previous) and (our > next)) max++;
        else if ((our < previous) and (our < next)) min++;
        previous = our; our = next;
    }

    if (max > min) cout << "MAX";
    else if (max < min) cout << "MIN";
    else cout << "EQUAL";
    return 0;
}
