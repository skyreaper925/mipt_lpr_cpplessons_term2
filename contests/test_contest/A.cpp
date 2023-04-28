// all squares not more then 100
#include <iostream>

using namespace std;

void squares_before(int n = 100)
{
    for (int i = 1; i * i <= n; ++i)
        cout << i * i << ' ';
    cout << endl;
}

int main()
{
    squares_before();
    return 0;
}