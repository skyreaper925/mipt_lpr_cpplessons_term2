// journey
#include <iostream>
#include <algorithm>

using namespace std;


void input_array(int *ptr, const int size)
{
    for (int i = 0; i < size; ++i && ++ptr)
        cin >> *ptr;
}


//int last_reachable(const int *list, const int size, const int major)
//{
//    int max_index = 0, i = 0, max = 0;
//    while (i < size and list[i] <= major)
//    {
//        if (list[i] >= max)
//            max_index = i;
//        ++i;
//    }
//    return max_index;
//}


int riding(const int *chargers, const int size, const int capacity)
{
    int left = capacity, passed = 0, rechargings = 0;
    bool possible = true;
    for (int i = 0; i < size + 1; ++i)
    {
        if (chargers[i] - passed > left)
        {
            if (passed && capacity >= chargers[i] - passed)
            {
                left = capacity - (chargers[i] - passed);
                rechargings += 1;
            }
            else
            {
                possible = false;
                break;
            }
        }
        else
        {
            left -= (chargers[i] - passed);
        }
        passed = chargers[i];
    }
    if (possible)
    {
        return rechargings;
    }
    else
    {
        return -1;
    }
}


int main()
{
    int N, k, S;
    cin >> N >> k >> S;
    int *chargers = new int[S + 1];
    input_array(chargers, S);
//    std::sort(chargers, chargers + S);
    chargers[S] = N;
    cout << riding(chargers, S, k) << endl;
    delete[] chargers;
    return 0;
}