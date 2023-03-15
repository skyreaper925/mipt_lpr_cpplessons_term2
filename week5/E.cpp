// Работа с памятью
#include <iostream>

using namespace std;

bool reserve_memory(int* ptr, size_t N)
{
    if (N)
    {
        ptr = new int[N];
        return true;
    }

    else return false;
}


void free_memory(int* ptr)
{
    if (ptr)
        delete [] ptr;
}


int main() {
    size_t N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << ((reserve_memory(ptr, N)) ? "Success" : "Failure") << endl;
    free_memory(ptr);
    return 0;
}