#include <iostream>
#include <vector>

using namespace std;


void input_arr(int *arr, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
        cin >> arr[i];
}


int min_len(int *arr, const size_t size)
{
    const size_t max_size = 10000;
    //first trivial case
    if (size == 2)
        return arr[1] - arr[0];

    //second trivial case
    if (size == 3)
        return min(arr[1] - arr[0], arr[2] - arr[0]);

    //searching for min in greedy algo taking the min between (curr and prev) and (curr and next))
    auto lens = new int[max_size]{0, arr[1] - arr[0], arr[2] - arr[0]};
    for (size_t i = 3; i < size; ++i)
        lens[i] = min(lens[i - 1], lens[i - 2]) + (arr[i] - arr[i - 1]);

    int tmp = lens[size - 1];
    delete[] lens;
    return tmp;
}


int main()
{
    size_t size;
    cin >> size;
    auto nails = new int[size];
    input_arr(nails, size);
    cout << min_len(nails, size) << endl;
    delete[] nails;
    return 0;
}