// Числа Фибоначчи
#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;

int fibonacci(unsigned i)
{
    if (i == 0 or i == 1) return i;
    return fibonacci(i-1) + fibonacci(i-2);
}

int main()
{
    int i;
    cin >> i;
    auto start = chrono::steady_clock::now();
    cout << fibonacci(i) << endl;
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    // cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    return 0;
}
