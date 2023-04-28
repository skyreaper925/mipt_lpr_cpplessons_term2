// Сдвиг по фазе
#include <iostream>
using namespace std;

#ifndef N
#define N 2 // actual size of the array
#endif


void shiftRight(int (&a)[N], unsigned k=1)
{
    int b[N];
    for (int i = 0; i < N - k; i++) b[i+k]= a[i];
    for (int i = 0; i < k; i++) b[i]= a[N+i-k];
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
    shiftRight(a);
    cout_array(a);
    return 0;
}
