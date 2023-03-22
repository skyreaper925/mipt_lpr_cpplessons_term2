// time remaing
#include <iostream>
#include <string>
using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    int n = 2;
    int hours = 0, minutes = 0, seconds = 0;
    struct Time moments[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> moments[i].hours >> moments[i].minutes >> moments[i].seconds;
        seconds += (moments[i].hours * 3600) + (moments[i].minutes * 60) + moments[i].seconds;
    }

    seconds = seconds % (24 * 3600);
    hours = (seconds / 3600) % 24; seconds -= hours * 3600;
    minutes = (seconds / 60) % 60; seconds -= minutes * 60;
    cout << hours << ':' << minutes << ':' << seconds;
    return 0;
}