// matrix multiplication
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int *create_sizes(const int *arr1, size_t size1)
{
    // вычисляем размер нового массива
    size_t size2 = 2 * (size1 - 1);
    // создаем новый массив
    int *arr2 = new int[size2];
    arr2[0] = arr1[0], arr2[size2 - 1] = arr1[size1 - 1];
    // индекс для нового массива
    size_t j = 1;
    for (size_t i = 1; i < size1 - 1; ++i, j += 2)
    {
        // копируем текущий элемент
        arr2[j] = arr1[i];
        arr2[j + 1] = arr1[i];
    }
    delete[] arr1;
    // возвращаем новый массив
    return arr2;
}


void arr_print(int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << ' ';

    cout << endl;
}


int main()
{
    size_t n;
    cin >> n;
    int table[n - 1][n - 1];
    size_t m = 2 * (n - 1);
    auto sizes = new int[m];
    for (int i = 0; i < n; i++)
        cin >> sizes[i];

    sizes = create_sizes(sizes, n);
//    arr_print(sizes, m);
    memset(table, 0x3f, sizeof(table));
    for (size_t i = 0; i < n - 1; i++)
        table[i][i] = 0;


    for (size_t len = 2; len <= n - 1; len++)
    {
        for (size_t i = 0; i <= n - 1 - len; i++)
        {
            size_t j = i + len - 1;
            for (size_t k = i; k < j; k++)
            {
                table[i][j] = min(table[i][j], table[i][k] + table[k + 1][j] + sizes[i] * sizes[k + 1] * sizes[j]);
            }
        }
    }

    cout << table[0][n - 1 - 1] << endl;
    delete[] sizes;
    return 0;
}
