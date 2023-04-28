// Обратный порядок
#include <iostream>
using namespace std;

#ifndef N
#define N 4 // actual size of the array
#endif


void reverseArray(int (&a)[N])
{
    int b[N];
    for (int i = 0; i < N; i++) b[N-1-i] = a[i];
    for (int i = 0; i < N; i++) a[i] = b[i];
}


void read_array (int (&a)[N])
{
    for (int i = 0; i < N; i++) cin >> a[i];
}


void cout_array (int (&a)[N])
{
    for (int i = 0; i < N; i++) cout << a[i] << ' ';
    cout << endl;
}


int main()
{
    int a[N];
    read_array(a);
    reverseArray(a);
    cout_array(a);
    return 0;
}
