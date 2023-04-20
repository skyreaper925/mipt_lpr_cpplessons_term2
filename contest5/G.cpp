#include <iostream>
#include <algorithm>

using namespace std;

void input_array(int *ptr, const size_t size)
{
    for (size_t i = 0; i < size; ++i && ++ptr)
        cin >> *ptr;
}

int array_sum(int *ptr, const size_t size)
{
    int ans = 0;
    for (size_t i = 0; i < size; ++i && ++ptr)
        ans += *ptr;

    return ans;
}

int redistribution(int *ptr, const size_t size)
{
    int operations = 0;
    sort(ptr, ptr + size);
    if (array_sum(ptr, size) % size)
        return -1;

    else
    {
        while (ptr[0] != ptr[size - 1])
        {
            ptr[size - 1]--;
            ptr[0]++;
            operations++;
            sort(ptr, ptr + size);
        }
    }

    return operations;
}

int main()
{
    size_t n;
    cin >> n;
    int *computers = new int[n];
    input_array(computers, n);
    cout << redistribution(computers, n) << endl;
    delete[] computers;
    return 0;
}