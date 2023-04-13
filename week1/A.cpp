// Проверка на палиндромичность
#include <iostream>
#include <cmath>
using namespace std;

//int number_length (int n)
//{
//    int k = 0;
//    while (n)
//    {
//        k++;
//        n /= 10;
//    }
//
//    return k;
//}
//
//bool palindrome (int n, int k)
//{
//    for (int i = 1; i <= k / 2; i++)
//    {
//        int a = int(pow(10, i)); int b = int(pow(10, k - i));
//        int first = n % a; int last = n / b;
//        if (first != last) {return false;}
//    }
//
//    return true;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    if (palindrome(n, number_length(n))) {cout << "Yes";}
//    else {cout << "No";}
//    return 0;
//}

// Проверка на палиндромичность
#include <iostream>
#include <cmath>
using namespace std;

int revert (int n, int k)
{
    int revert_n = 0;
    for (int i = 1; i <= k; i++)
    {
        int a = n % 10;
        revert_n = revert_n*10 + a;
        n /= 10;
    }

    return revert_n;
}

int number_length(int (&a)[N])
{
    int k = 0;
    while (n)
    {
        k++;
        n /= 10;
    }

    return k;
}



int main()
{
    int n;
    cin >> n;
    cout << ((revert(n, number_length(n)) == n) ? "Yes" : "No") << endl;
    return 0;
}



