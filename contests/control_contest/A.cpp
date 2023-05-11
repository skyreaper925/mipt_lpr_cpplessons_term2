// start 7 fin 4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int convert(int number) // перевод из 7-й в 10-ю СС
{
    int dec10 = 1;
    int ans = 0;
    int dec7 = 1;
    while (number / dec10 != 0)
    {
        ans += (number / dec10) % 10 * dec7;
        dec10 *= 10;
        dec7 *= 7;
    }
    return ans;
}

void beautify(int res)
{
    vector<int> numbers;
    while (res > 0)
    {
        // переводим из 10-й в 4-ю СС поразрядно
        int number = res % 4;
        numbers.push_back(number);
        res /= 4;
    }

    //так как перевод начинался с младшего разряда, нам следует обратить массив
    reverse(numbers.begin(), numbers.end());
    for (int number: numbers)
        cout << number;

    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    int *a = new int[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = convert(a[i]);
        ans += a[i];
    }
    beautify(ans);
    delete[]a;
    return 0;
}