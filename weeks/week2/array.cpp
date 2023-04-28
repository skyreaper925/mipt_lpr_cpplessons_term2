#include <iostream>
using namespace std;


void read_array (int (&a)[int size])
{
    for (int i = 0; i < size; i++) cin >> a[i];
}


void cout_array (int (&a)[int size])
{
    for (int i = 0; i < size; i++) cout << a[i] << ' ';
    cout << endl;
}