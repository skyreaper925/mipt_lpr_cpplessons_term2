// Массив разностей
#include <iostream>
using namespace std;


int main()
{
    int arr[1000], n = 0, curr, *ptr = arr;
    while (cin >> curr && curr != 0)
    {
        *ptr = curr;
        ptr++;
        n++;
    }

    for (int i = 0; i < n - 1; i++)
        cout << *(arr+i) - *(arr+i+1) << " ";

    return 0;
}