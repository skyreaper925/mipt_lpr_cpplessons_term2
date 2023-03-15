// Короткая работа с указателями
#include <iostream>
using namespace std;


int main()
{
    short int (*parr)[10];
    for (int i = 0; i < 10; ++i)
        *parr[i] = i;

    for (int i = 0; i < 10; ++i)
        cout << parr[i] << ' ';

    cout << endl;
    for (int i = 0; i < 10; ++i)
        cout << *parr[i] << ' ';

    for (int i = 0; i < 10; i+=2)
        *parr[i] *= *parr[i];

    cout << endl;
    for (int i = 0; i < 10; ++i)
        cout << *parr[i] << ' ';

    return 0;
}
