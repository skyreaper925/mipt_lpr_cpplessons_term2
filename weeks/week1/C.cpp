// Проверка на високосность
#include <iostream>
#include <cmath>
using namespace std;


bool leap_check (int year)
{
    if (!(year % 4))
    {
        if (!(year % 400)) return true;
        if (!(year % 25)) return false;
        else return true;
    }

    return false;
}


int main()
{
    int year;
    cin >> year;
    cout << (leap_check(year) ? "Yes" : "No") << endl;
    return 0;
}
