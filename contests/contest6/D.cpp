// grasshopper
#include <iostream>
#include <cassert>


using namespace std;


const size_t max_size = 61;
long long amounts[max_size] = {1, 1, 2, 4};


long long amount(const size_t target)
{
    if (!(amounts[target]))
        amounts[target] = amount(target - 1) + amount(target - 2) + amount(target - 3);

    return amounts[target];
}


int main()
{
//    assert(amount(4) == 7);
//    assert(amount(2) == 2);
    size_t x0;
    cin >> x0;
    cout << amount(x0) << endl;
    return 0;
}