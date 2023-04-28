// Egypt
#include <iostream>
#include <cmath>

using namespace std;


void decomposite(int arr[], int numerator, int denominator)
{
    int dens = 0;
    while (numerator)
    {
        int new_den = ((denominator + numerator - 1) / numerator); //why ceil doesn't work?
        arr[dens++] = new_den;
        numerator = numerator * new_den - denominator;
        denominator *= new_den;
    }
    for (int i = 0; i < dens; i++)
        cout << arr[i] << ' ';
    cout << endl;
}


int main()
{
    int M, N;
    cin >> M >> N;
    int denominators[N];
    for (int i = 0; i < N; ++i)
        denominators[i] = 0;

    decomposite(&denominators[N], M, N);
    return 0;
}