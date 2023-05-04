#include <iostream>
#include <algorithm>

using namespace std;

const long long int MAX_N = 10000;

long long int n;
auto arr = new long long int[MAX_N];
auto subseqs = new long long int[MAX_N][MAX_N];
auto subseqs_lengths = new long long int[MAX_N];


void arr_input(long long int *arr, const size_t size)
{
    for (int i = 0; i < size; ++i and ++arr)
        cin >> *arr;
}


int main()
{
    cin >> n;
    arr_input(arr, n);
    auto curr_subseq = new long long int[MAX_N];
    auto curr_subseq_len = 1;
    curr_subseq[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > curr_subseq[curr_subseq_len - 1])
        {
            curr_subseq[curr_subseq_len] = arr[i];
            curr_subseq_len++;
        }
        else
        {
            for (int j = 0; j < curr_subseq_len; ++j)
            {
                subseqs[subseqs_lengths[curr_subseq_len - 1]][j] = curr_subseq[j];
            }
            subseqs_lengths[curr_subseq_len - 1] = curr_subseq_len;
            curr_subseq[0] = arr[i];
            curr_subseq_len = 1;
        }
    }
    for (int j = 0; j < curr_subseq_len; ++j)
    {
        subseqs[subseqs_lengths[curr_subseq_len - 1]][j] = curr_subseq[j];
    }
    subseqs_lengths[curr_subseq_len - 1] = curr_subseq_len;

    auto max_subseq = new long long int[MAX_N];
    auto max_subseq_len = 0;
    for (int i = 0; i < n; i++)
    {
        if (subseqs_lengths[i] > max_subseq_len)
        {
            max_subseq_len = subseqs_lengths[i];
            for (int j = 0; j < max_subseq_len; ++j)
            {
                max_subseq[j] = subseqs[i][j];
            }
        }
    }


    reverse(max_subseq, max_subseq + max_subseq_len);
    for (int i = 0; i < max_subseq_len; i++)
    {
        cout << max_subseq[i] << " ";
    }
    cout << max_subseq_len << endl;
    delete[] arr;
    delete[] subseqs;
    delete[] subseqs_lengths;
    delete[] curr_subseq;
}