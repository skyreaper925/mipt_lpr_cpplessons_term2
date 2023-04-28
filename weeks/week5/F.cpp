// Работа с памятью
#include <iostream>
#include <cstring>

using namespace std;

void input_array(char* ptr, size_t N)
{
    for (size_t i = 0; i < N; ++i && ptr++)
        cin >> *ptr;
}


char *resize(const char *buf, size_t size, size_t new_size)
{
    char *ptr = new char[new_size];
//    for (size_t i = 0; i < size; ++i)
//        *ptr+i = *buf+i;

    memcpy(ptr, buf, min(size, new_size));
    delete [] buf;

    return ptr;
}

void print(const char* ptr, size_t N)
{
    for (char i = 0; i < N; ++i)
        cout << *(ptr+i) << " ";
}

int main()
{
    size_t prev, curr;
    cin >> prev;
    char *a = new char[prev];
    input_array(a, prev);
    cin >> curr;
    print (resize (a, prev, curr), curr);
    delete[] a;
    return 0;
}