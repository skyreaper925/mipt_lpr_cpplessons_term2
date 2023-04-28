// upper_bound
#include <iostream>
#include <algorithm>

using namespace std;

void input_segments(double *ptr, const size_t N)
{
    for (int i = 0; i < N; ++i && ++ptr)
        cin >> *ptr;
}

double *upper_bound(double *begin, double *end, double key)
{
    auto distance = (end - begin);
    auto result = begin;
    while (distance > 0)
    {
        auto half = distance / 2;
        auto mid = result + half;
        if (*mid <= key)
        {
            result = mid + 1;
            distance -= half + 1;
        }
        else
            distance = half;
    }
    return result;
}


int main()
{
    size_t N;
    cin >> N;
    auto *arr = new double[N];
    input_segments(arr, N);
    double key;
    cin >> key;
    cout << *upper_bound(arr, arr + N, key) << endl;
    delete[] arr;
    return 0;
}