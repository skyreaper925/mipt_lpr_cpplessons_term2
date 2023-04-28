// life_trifles
#include <iostream>

using namespace std;


int decomposition(const int *list, int size, int money)
{
    int times, number = 0, i = size - 1;
    while (money)
    {
        times = money / list[i];
        number += times;
        money -= times * list[i];
        --i;
    }
    return number;
}


int main()
{
    int M;
    cin >> M;
    int *list = new int[6]{1, 7, 28, 49, 63, 98};
    cout << decomposition(list, 6, M) << endl;
    delete[] list;
    return 0;
}