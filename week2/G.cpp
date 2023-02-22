// Одиночка
#include <iostream>
using namespace std;

#ifndef N
#define N 9 // actual size of the array
#endif


int findUnique(int (&a)[N])
{
    int result = a[0];
    for (int i = 1; i < N; i++) result ^= a[i];
    return result;
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
    cout << findUnique(a);
    return 0;
}
