// grasshopper
#include <iostream>
#include <cassert>


using namespace std;


const size_t max_size = 61;
long long amounts[max_size] = {1, 1, 2, 4};


void initialize_arr(const size_t size = max_size)
{
    for (size_t i = 4; i < size; ++i)
    {
        amounts[i] = 0;
    }
}


long long amount(const size_t target)
{
    if (!(amounts[target]))
    {
        amounts[target] = amount(target - 1) + amount(target - 2) + amount(target - 3);
    }
    return amounts[target];
}


int main()
{
    initialize_arr();
//    assert(amount(4) == 7);
//    assert(amount(2) == 2);
    size_t x0;
    cin >> x0;
    cout << amount(x0) << endl;
    return 0;
}