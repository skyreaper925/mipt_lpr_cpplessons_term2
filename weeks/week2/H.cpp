// Транспозиция
#include <iostream>
using namespace std;

#ifndef N
#define N 2 // actual size of the array
#endif

#ifndef M
#define M 2 // actual size of the array
#endif


void print_transposed(int (&array)[N][M])
{
    int result [M][N];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) result[j][i] = array[i][j];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) cout << result[i][j] << ' ';
        cout << endl;
    }
}


void read_array (int (&a)[N][M])
{
    for (auto & i : a) for (int j = 0; j < M; j++) cin >> i[j];
}


void cout_array (int a[], int size=N)
{
    for (int i = 0; i < size; i++) cout << a[i] << ' ';
    cout << endl;
}


int main()
{
    int a[N][M];
    read_array(a);
    print_transposed(a);
    return 0;
}
