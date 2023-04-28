// Последний ноль
#include <iostream>
using namespace std;

#ifndef N
#define N 5 // actual size of the array
#endif


int findLastZero(int (&a)[N])
{
    int left = 0, right = N-1, middle = (left + right) / 2;
    while (left < right)
    {
        if (a[middle] == 0)
        {
            if (a[middle + 1] == 1) return middle;
            else left = middle;
        }

        else
        {
            if (a[middle - 1] == 0) return middle - 1;
            else right = middle;
        }

        middle = (left + right) / 2;
    }

    return middle;
}


void read_array (int (&a)[N])
{
    for (int & i : a) cin >> i;
}


void cout_array (int a[], int size=N)
{
    for (int i = 0; i < size; i++) cout << a[i] << ' ';
    cout << endl;
}


int main()
{
    int a[N];
    read_array(a);
    cout << findLastZero(a);
    return 0;
}
