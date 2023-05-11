//brand new coin
#include <algorithm>
#include <iostream>

using namespace std;


int main()
{
    size_t n;
    const size_t max_size = 10e6;
    cin >> n;
    auto cost = new long long[max_size];
    //creating new arr with prices
    for (size_t i = 0; i < n; ++i)
        cin >> cost[i];

    for (size_t i = n; i < max_size; ++i)
        cost[i] = max_size;

    long long money, max_num;
    cin >> money >> max_num;
    sort(cost, cost + max_size);
    size_t i = 0, ans = 0;
    //starting the bypass searching for most profitable bargain
    while (i < n && money > 0)
    {
        //num of coins we can buy this day
        auto num = min(max_num, money / cost[i]);
        //some of the money are spent
        money -= num * cost[i];
        //now we bought more coins. let's increment the whole number
        ans += num;
        //transition to the next arr elem
        ++i;
    }
    cout << ans;
}