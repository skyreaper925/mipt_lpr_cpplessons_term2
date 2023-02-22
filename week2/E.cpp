// Неубывающее слияние
#include <iostream>
using namespace std;

#ifndef N
#define N 5 // actual size of the array
#endif


void mergeArrays(int (&first)[N], int (&second)[N], int (&result)[2 * N])
{
    int i_result = 0, i_first = 0, i_second = 0;
    while (i_result < 2*N)
    {
        if (first[i_first] <= second[i_second])
        {
            result[i_result] = first[i_first];
            i_first++;
        }

        else
        {
            result[i_result] = second[i_second];
            i_second++;
        }

        i_result++;
        if (i_first == N)
        {
            while (i_second < N)
            {
                result[i_result] = second[i_second];
                i_result++;
                i_second++;
            }

            break;
        }

        if (i_second == N)
        {
            while (i_first < N)
            {
                result[i_result] = first[i_first];
                i_result++;
                i_first++;
            }

            break;
        }
    }
}


void read_array (int (&a)[N])
{
    for (int & i : a) cin >> i;
}


void cout_array (int a[], int size=N)
{
    for (int i = 0; i < size; i++) cout << a[i] << ' ';
    cout << endl;
}


int main()
{
    int first[N], second[N], result[2*N];
    read_array(first); read_array(second);
    mergeArrays(first, second, result);
    cout_array(result, 2*N);
    return 0;
}
