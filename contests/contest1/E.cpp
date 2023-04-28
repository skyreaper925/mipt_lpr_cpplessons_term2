// Сложение векторов
#include <iostream>
#include <string>
using namespace std;

struct VectorN
{
    int dimension;
    int *coordinates;
};

int main()
{
    int N, n = 2;
    cin >> N;
    struct VectorN vectors[n+1];
    vectors[n].dimension = N; vectors[n].coordinates = new int[N]();
    for (int j = 0; j < n; ++j)
    {
        vectors[j].dimension = N;
        vectors[j].coordinates = new int [N]();
        for (int i = 0; i < N; ++i)
        {
            cin >> vectors[j].coordinates[i];
            vectors[n].coordinates[i] += vectors[j].coordinates[i];
        }
    }

    cout << vectors[n].dimension << ' ';
    for (int j = 0; j < N; ++j)
        cout << vectors[n].coordinates[j] << ' ';

    for (int j = 0; j < n+1; ++j)
        delete[] vectors[j].coordinates;

    return 0;
}