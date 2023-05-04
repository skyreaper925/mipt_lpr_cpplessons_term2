// fibonacci squares
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;


const size_t max_size = 41;
long long squares[max_size];


void initialize_arr(const size_t size)
{
    squares[0] = 1, squares[1] = 1, squares[2] = 4;
    for (size_t i = 3; i < size; ++i)
        squares[i] = 0;
}


long long fibonacci_square(size_t number)
{
    if (squares[number]) return squares[number];
    else
    {
        squares[number] = 2 * fibonacci_square(number - 1) + 2 * fibonacci_square(number - 2) - fibonacci_square
                (number - 3);
        return squares[number];
    }
}


int main()
{
    size_t N;
    cin >> N;
    initialize_arr(max_size);
    assert(fibonacci_square(1) == 1);
    assert(fibonacci_square(5) == 64);
    cout << fibonacci_square(N) << endl;
    return 0;
}