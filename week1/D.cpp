// Характер массива
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n, last, previous = 0, next = 0;
    cin >> n >> last;
    for (int i = 1; i <= n; i++)
    {
        if (i > last) previous++;
        if (i < last) next++;
        last = i;
    }

    cout << (((previous - next) > 0) ? "MAX" : "MIN") << endl;
    return 0;
}
