// Стандартные функции
#include <iostream>

using namespace std;

void input_array(int* ptr, size_t N)
{
    for (int i = 0; i < N; ++i && ptr++)
        cin >> *ptr;
}


void reverse(int* ptr, size_t N)
{
    for (int i = 0; i < N/2; ++i)
    {
        int tmp = *(ptr+i);
        *(ptr+i) = *(ptr+N-i-1);
        *(ptr+N-i-1) = tmp;
    }
}


void print(const int* ptr, size_t N)
{
    for (int i = 0; i < N; ++i)
        cout << *(ptr+i) << " ";
}


int main()
{
    size_t N;
    cin >> N;
    int* ptr = new int[N];
    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);
    delete [] ptr;
    return 0;
}