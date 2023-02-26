// Блинная сортировка
#include <iostream>
using namespace std;

#ifndef N
#define N 7 // actual size of the array
#endif

int array_min_i (int first, int last, int (&a)[N])
{
    int min_i = first;
    for (int i = first+1; i < last; ++i)
        if (a[i] <= a[min_i])
            min_i = i;

    return min_i;
}


void pancakeSort(int (&a)[N])
{
    for (int i = 0; i <= N-2; ++i)
    {
        int min_i = array_min_i(i, N, a);
        for (int j = i; j < i+min_i/2; ++j)
            if (j <= i+min_i-j)
                swap (a[j], a[i+min_i-j]);
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
    pancakeSort(a);
    array_cout(a);
    return 0;
}