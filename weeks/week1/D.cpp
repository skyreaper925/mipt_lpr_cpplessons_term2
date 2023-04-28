// Характер массива
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n, last, previous = 0, next = 0, current;
    cin >> n >> last;
    for (int i = 1; i < n; i++) {
        cin >> current;
        if (current > last) previous++;
        if (current < last) next++;
        last = current;
    }

    cout << (((previous - next) > 0) ? "MAX" : "MIN") << endl;
    return 0;
}
