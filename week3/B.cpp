// Сортировка с двойным выбором
#include <iostream>
using namespace std;

#ifndef N
#define N 1 // actual size of the array
#endif

int array_min_i (int first, int last, int (&a)[N])
{
    int min_i = first;
    for (int i = first+1; i < last; ++i)
        if (a[i] <= a[min_i])
            min_i = i;

    return min_i;
}

int array_max_i (int first, int last, int (&a)[N])
{
    int max_i = first;
    for (int i = first+1; i < last; ++i)
        if (a[i] >= a[max_i])
            max_i = i;

    return max_i;
}

void doubleSelectSort(int (&a)[N])
{
    for (int i = 0; i < N; ++i)
    {
        swap (a[i], a[array_max_i(i, N-i, a)]);
        swap (a[N-i-1], a[array_min_i(i, N-i, a)]);
    }

}


void array_read (int (&a)[N])
{
    for (int & i : a) cin >> i;
}


void array_cout (int (&a)[N])
{
    for (int i : a) cout << i << ' ';
    cout << endl;
}


int main()
{
    int a[N];
    array_read(a);
    doubleSelectSort(a);
    array_cout(a);
    return 0;
}