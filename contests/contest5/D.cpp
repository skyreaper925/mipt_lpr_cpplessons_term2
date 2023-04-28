// riding
#include <iostream>
#include <algorithm>

using namespace std;


void arr_print(int *ptr, int N)
{
    for (int i = 0; i < N; ++i && ++ptr)
        cin >> *ptr;
}


int archiving(const int *list, int size, int disk)
{
    int number = 0, i = 0;
    while (i < size and disk - list[i] > 0)
    {
        disk -= list[i];
        ++number;
        ++i;
    }
    return number;
}


int main()
{
    int S, N;
    cin >> S >> N;
    int *list = new int[N];
    input_array(list, N);
//    print_array(list, N);
    std::sort(list, list + N);
    cout << archiving(list, N, S) << endl;
//    print_array(list, N);
    delete[] list;
    return 0;
}