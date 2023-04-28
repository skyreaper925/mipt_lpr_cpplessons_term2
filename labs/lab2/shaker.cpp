// Коктейль
#include <iostream>
using namespace std;

#ifndef N
#define N 7 // actual size of the array
#endif


void forward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx)
{
    if (arr[begin_idx] > arr[end_idx])
        swap(arr[begin_idx], arr[end_idx]);
}


void backward_step(unsigned arr[], unsigned const begin_idx, unsigned const end_idx)
{
    if (arr[begin_idx] > arr[end_idx])
        forward_step(arr, begin_idx, end_idx);
}

void shaker_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx)
{
    bool sorted;
    unsigned begin = begin_idx;
    unsigned end = end_idx;
    while (begin < end)
    {
        sorted = true;
        for (int i = begin; i < end - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
                sorted = false;

            forward_step(arr, i, i + 1);
        }

        sorted = true;
        for (int i = end - 1; i > begin; --i)
        {
            if (arr[i - 1] > arr[i])
                sorted = false;

            backward_step(arr, i - 1, i);
        }

        ++begin;
        --end;
    }
}


void array_read (unsigned (&a)[N])
{
    for (unsigned & i : a) cin >> i;
}


void array_cout (unsigned (&a)[N])
{
    for (unsigned i : a) cout << i << ' ';
    cout << endl;
}


int main()
{
    unsigned a[N];
    array_read(a);
    shaker_sort(a, 0, N);
    array_cout(a);
    return 0;
}