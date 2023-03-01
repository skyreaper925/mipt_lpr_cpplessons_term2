// Расчёска
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;

long long int comb_step(long long int (&arr)[], long long int begin, long long int end, long long int step)
{
    long long int step_permutations = 0;
    for (long long int i = begin; i < end; i += step)
        if (arr[i] > arr[i + step])
        {
            swap(arr[i], arr[i + step]);
            step_permutations += 1;
        }

    return step_permutations;
}


long long int comb_sort(long long int (&arr)[], long long int size, long long int begin, long long int end)
{
    bool sorted = false;
    long long int permutations = 0;
    long long int delta_permutations;
    long long int step = (end - begin) / 2;
    long long int min_step = 1;
    while (not(sorted))
    {
        delta_permutations = comb_step(arr, 0, size, step);
        if (not(delta_permutations))
            sorted = true;
        else permutations += delta_permutations;
        step = max(step/2, min_step);
        delta_permutations = 0;
    }

    return permutations;
}


ofstream fout;

void protocol (long long int test_number, long long int dots_number,
               long long int n, long long int N)
{
    fout.open("C://Users/volod/CLionProjects/mipt_lpr_cpplessons_term2/lab2/comb.txt", ios::app);
//    fout << "test: " << test_number << ';' <<  endl;
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
        long long int permutations = comb_sort(a, i, 0, i);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> seconds = end - start;
        if (permutations)
            fout << i << ' ' << permutations << ' ' << seconds.count() << "\n";
    }

    fout << endl;
//    cout << "test: " << test_number << ';' << endl;
}


int main()
{
    long long int dots_number = 63, n = 6, N = 568, test_number = 5;
//    long long int dots_number, n, N, test_number;
//    cout << "Number of dots:"; cin >> dots_number;
//    cout << "Minimum size of array:"; cin >> n;
//    cout << "Maximum size of array:"; cin >> N;
//    cout << "Number of tests:"; cin >> test_number;
    for (int i = 1; i <= test_number; ++i)
        protocol(i, dots_number, n, N);

    fout.close();
    return 0;
}