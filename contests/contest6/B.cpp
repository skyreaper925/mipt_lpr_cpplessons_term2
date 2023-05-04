// log cutting
#include <iostream>
#include <cassert>

using namespace std;

const size_t max_size = 501;
auto prices = new int[max_size]{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
auto max_prices = new int[max_size]{0};

void initialize_arr(const size_t size = max_size)
{
    for (size_t i = 11; i < size; ++i)
    {
        prices[i] = 0;
        max_prices[i] = 0;
    }
}

int cutting(const size_t number, const size_t defined = 10)
{
    if (max_prices[number] != 0)
    {
        return max_prices[number];
    }

    if (prices[number] and number <= 3)
    {
        max_prices[number] = prices[number];
        return prices[number];
    }
    else
    {
        for (size_t i = 1; i <= min(number, defined); ++i)
        {
            max_prices[number] = max(max_prices[number], cutting(number - i) + prices[i]);
        }
        return max_prices[number];
    }
}

int main()
{
    initialize_arr(max_size);
//    assert(cutting(4) == 10);
//    assert(cutting(30) == 90);
//    assert(cutting(17) == 48);
    size_t N;
    cin >> N;
    cout << cutting(N) << endl;
    return 0;
}