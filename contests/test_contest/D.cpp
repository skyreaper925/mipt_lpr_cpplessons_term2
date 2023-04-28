// reduction
#include <iostream>

using namespace std;

unsigned long long digits_sum(unsigned long long a)
{
    unsigned long long ans = 0;
    while (a)
    {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}

unsigned long long redux(unsigned long long a)
{
    unsigned long long ans = a;
    while (ans > 9)
        ans = digits_sum(ans);

    return ans;
}


int main()
{
    unsigned long long a;
    cin >> a;
    cout << redux(a) << endl;
//    cout << digits_sum(a) << endl;
    return 0;
}