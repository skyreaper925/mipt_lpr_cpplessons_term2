

// thirst
#include <iostream>
#include <algorithm>

using namespace std;

struct Lection
{
    int begin = 0;
    int end = 0;
};

void input_lections(Lection *const ptr, const int size)
{
    for (int i = 0; i < size; ++i)
        cin >> ptr[i].begin >> ptr[i].end;
}


int maximize(Lection *list, int size)
{
    int lections = 0, end = 0;
    for (int i = 0; i < size; ++i)
    {
        if (list[i].begin >= end)
        {
            end = list[i].end;
            ++lections;
        }
    }
    return lections;
}


int main()
{
    int N;
    cin >> N;
    auto *lections = new Lection[N];
    input_lections(lections, N);
//    print_lections(lections, N);
    cout << maximize(lections, N) << endl;
    delete[] lections;
    return 0;
}