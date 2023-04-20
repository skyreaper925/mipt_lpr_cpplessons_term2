// life_trifles_2
#include <iostream>

using namespace std;


void input_array(int *ptr, int N)
{
    for (int i = 0; i < N; ++i && ++ptr)
        cin >> *ptr;
}


int decomposition(const int *list, int size, int money)
{
    int times, number = 0, i = size - 1;
    while (money)
    {
        times = money / list[i];
        number += times;
        money -= times * list[i];
        --i;
    }
    return number;
}


int main()
{
    int k, M;
    cin >> k;
    int *notes = new int[k];
    input_array(notes, k);
    cin >> M;
    cout << decomposition(notes, k, M) << endl;
    delete[] notes;
    return 0;
}