// Шелл
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

long long int gr_Fib_less_than_given(long long int given)
{
    long long int fi2 = 0, fi1 = 1, fi = fi2 + fi1;
    while (fi < given)
    {
        fi2 = fi1;
        fi1 = fi;
        fi = fi2 + fi1;
    }

    return fi1;
}


long long int prev_Fib(long long int given)
{
    long long int fi1 = 0, fi = 1, temp;
    while (fi < given)
    {
        temp = fi;
        fi += fi1;
        fi1 = temp;
    }

    return fi1;
}


long long int shell_sort(long long int (&arr)[], long long int size, int step)
{
    long long int d, permutations = 0, min_d = 0;
    switch (step)
    {
        case 1: d = size; break;
        case 2: d = pow(2, log2(size+1)) - 1 ; break;
        case 3: d = gr_Fib_less_than_given(size);
    }

    while (d > 0)
    {
        for (long long int i = d; i < size; ++i)
        {
            long long int temp = arr[i]; long long int j = i;
            while (j >= d && arr[j - d] > temp)
            {
                arr[j] = arr[j - d];
                j -= d;
                ++permutations;
            }

            arr[j] = temp;
        }

        switch (step)
        {
            case 1: d = max(d/2, min_d); break;
            case 2: d = pow(2, log2(d+1)-1) - 1;
            case 3:
            {
                if (d == 1 and prev_Fib(d) == 1)
                    d = 0;

                else
                    d = prev_Fib(d);

                break;
            }
        }
    }

    return permutations;
}


ofstream fout;

void protocol (int d, long long int test_number, long long int dots_number,
               long long int n, long long int N)
{
    fout.open("C://Users/volod/CLionProjects/mipt_lpr_cpplessons_term2/lab2/shell.txt", ios::app);
    fout << "d: " << d << ", test: " << test_number << ';' <<  endl;
    long long int step = (N - n)/dots_number;
    for (long long int i = n; i < N; i += step)
    {
        long long int a[i];
        default_random_engine rng(i);
        uniform_int_distribution<unsigned> dstr(1, i);
        for (long long int j = 0; j < i; ++j)
            a[j] = dstr(rng);

        long long int number = a[dstr(rng)];
        auto start = chrono::steady_clock::now();
        long long int permutations = shell_sort(a, i, d);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> seconds = end - start;
//        fout << i << ' ' << permutations << ' ' << seconds.count() << "\n";
        fout << seconds.count() << "\n";
    }

    fout << endl;
    cout << "d: " << d << ", test: " << test_number << ';' <<  endl;
}


int main()
{
    long long int dots_number = 100, n = 10, N = 200000, test_number = 1;
//    long long int dots_number, n, N, test_number;
//    cout << "Number of dots:"; cin >> dots_number;
//    cout << "Minimum size of array:"; cin >> n;
//    cout << "Maximum size of array:"; cin >> N;
//    cout << "Number of tests:"; cin >> test_number;
    for (int i = 1; i <= test_number; ++i)
        protocol(3, i, dots_number, n, N);

    fout.close();
    return 0;
}