#include <iostream>
#include <cassert>

using namespace std;

int amount(size_t size)
{
    const size_t max_size = 100;
    auto amounts = new int[max_size]{0};
    for (int i = 1; i < 100; ++i)
    {
        if (i % 10)
            amounts[i] = amounts[i - 1] + 19 - (i / 10) * 2;
        else
            amounts[i] = amounts[i - 1] + 21 - (i / 10) * 2;
    }
    int tmp = amounts[size];
    delete[] amounts;
    return tmp;
};

int main()
{
//    assert(amount(99) == 999);
//    assert(amount(30) == 510);
//    assert(amount(97) == 997);
//    assert(amount(1) == 19);
    size_t n;
    cin >> n;
    cout << amount(n) << endl;
    return 0;
}