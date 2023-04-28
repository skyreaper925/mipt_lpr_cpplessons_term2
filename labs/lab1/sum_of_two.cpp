// Разложение
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;

long long const N = 200000;

long long int pair_full (long long int number, long long int size, long long int a[N])
{
    for (long long int i = 0; i < size-1; ++i)
        for (long long int j = i+1; j < size; ++j)
            if (a[i] + a[j] == number)
            {
//                cout << i+1 << ' ' << j+1 << endl;
                return 0;
            }

//    cout << 0 << ' ' << 0 << endl;
    return 0;
}


long long int pair_linear (long long int number, long long int size, long long int a[N])
{
    long long int left = 0, right = size - 1;
    while (left < right)
        if (a[left] + a[right] == number)
        {
//            cout << i << ' ' << i+1 << endl;
            return 0;
        }

        else if (a[left] + a[right] < number)
            ++left;

        else
            --right;
//    cout << 0 << ' ' << 0 << endl;
    return 0;
}


ofstream fout;

void protocol (bool search_type, bool case_type, long long int test_number, long long int dots_number=10,
               long long int n=100, long long int N=200000)
{
    fout.open("C://Users/volod/CLionProjects/mipt_lpr_cpplessons_term2/lab1/sum_of_two.txt", ios::out);
//    fout << "search: " << ((search_type) ? "full" : "linear") << ", ";
//    fout << "case: " << ((case_type) ? "mean" : "worst") << ", ";
//    fout << "test: " << test_number << ';' <<  endl;
    long long int step = (N - n)/dots_number;
    long long int a[N], number;
    for (long long int i = n; i < N; i += step)
    {
        default_random_engine rng(i);
        uniform_int_distribution<unsigned> dstr(1, i);
        for (long long int j = 0; j < i; ++j)
            a[j] = dstr(rng);

        if (not(case_type))
            number = 0;
        else
            number = a[dstr(rng)] + a[dstr(rng)];

        if (not(search_type))
            sort(a, a+i);

        auto start = chrono::steady_clock::now();
        if (search_type)
            pair_full(number, i, a);
        else
            pair_linear(number, i, a);

        auto end = chrono::steady_clock::now();
        chrono::duration<double> seconds = end - start;
        fout << seconds.count() << "\n";
    }
    fout << endl;
    cout << "search: " << ((search_type) ? "full" : "linear") << ", ";
    cout << "case: " << ((case_type) ? "mean" : "worst") << ", ";
    cout << "test: " << test_number << ';' << endl;
}


int main()
{
    long long int dots_number = 100, n = 100, N = 200000, test_number = 1;
//    long long int dots_number, n, N, test_number;
//    cout << "Number of dots:"; cin >> dots_number;
//    cout << "Minimum size of array:"; cin >> n;
//    cout << "Maximum size of array:"; cin >> N;
//    cout << "Number of tests:"; cin >> test_number;
    for (int i = 1; i <= test_number; ++i)
    {
        protocol(true, false, i, dots_number, n, N);
//        protocol(true, false, i, dots_number, n, N);
//        protocol(false, true, i, dots_number, n, N);
//        protocol(false, false, i, dots_number, n, N);
    }

    fout.close();
    return 0;
}