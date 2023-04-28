// Негативчик под конец
#include <iostream>
using namespace std;

#ifndef N
#define N 5 // actual size of the array
#endif


void moveNegativeToEnd(int (&a)[N])
{
    int b[N], iterator = 0, i = 0;
    while (iterator < N and i < N)
    {
        if (a[i] > 0)
        {
            b[iterator] = a[i];
            iterator++;
        }

        i++;
    }

    i = 0;
    while (iterator < N and i < N)
    {
        if (a[i] == 0)
        {
            b[iterator] = a[i];
            iterator++;
        }

        i++;
    }

    i = 0;
    while (iterator < N and i < N)
    {
        if (a[i] < 0)
        {
            b[iterator] = a[i];
            iterator++;
        }

        i++;
    }

    for (int j = 0; j < N; ++j) a[j] = b[j];
}


void read_array (int (&a)[N])
{
    for (int & i : a) cin >> i;
}


void cout_array (int (&a)[N])
{
    for (int i : a) cout << i << ' ';
    cout << endl;
}


int main()
{
    int a[N];
    read_array(a);
    moveNegativeToEnd(a);
    cout_array(a);
    return 0;
}
