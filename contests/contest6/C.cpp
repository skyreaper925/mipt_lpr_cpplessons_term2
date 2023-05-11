// log disassembly
#include <iostream>

using namespace std;

const size_t max_size = 100;
auto prices = new int[10]{1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
auto max_prices = new int[max_size]{1};


int cutting(const size_t number)
{
    if (max_prices[number] != 0)
        return max(max_prices[number], prices[number]);

    int m = 0;
    if (number != 0)
    {
        for (size_t i = 0; i < number; i++)
            m = max(m, cutting(number - i - 1) + prices[i]);
    }

    max_prices[number] = max(m, prices[number]);
    return max_prices[number];
}


void cuts(int number)
{
    //trivial case
    if (number % 10 == 0)
    {
        for (int i = 0; i < number / 10; ++i)
            cout << 10 << ' ';

        return;
    }
    //not trivial case: we will print cuts from the min-by-length
    int k = number % 10, s;
    s = cutting(k - 1);
    for (int i = 0; i < k; ++i)
    {
        //trivial moment in not trivial case
        if (k == 1)
        {
            cout << k << ' ';
            continue;
        }

        if (prices[k - 2 - i] + prices[i] == s)
        {
            if (k - 1 - i != 0)
                cout << i + 1 << ' ' << k - 1 - i << ' ';
            else
                cout << i + 1 << ' ';
            break;
        }
        else if (prices[k - 1] == s)
        {
            cout << k << ' ';
            break;
        }
    }
    //after working with the remainders we just print 10s
    for (int i = 0; i < number / 10; i++)
        cout << 10 << ' ';
}


int main()
{
    int N;
    cin >> N;
    cuts(N);
    return 0;
}
