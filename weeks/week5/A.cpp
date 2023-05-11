// Работа с указателями
#include <iostream>

using namespace std;


//void cout_array (int a[], int size)
//{
//    for (int i = 0; i <= size - 1; ++i)
//        cout << a[i] << ' ';
//
//    cout << endl;
//}


int main() {
    double number = 0;
    double *pnumber = &number;
    cout << pnumber << ' ' << *pnumber << endl;
    pnumber -= 3;
    cout << pnumber << ' ' << *pnumber << endl;
    pnumber += 5;
    cout << pnumber << ' ' << *pnumber << endl;
    return 0;
}
