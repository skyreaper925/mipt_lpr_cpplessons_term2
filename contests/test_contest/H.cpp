// unique numbers
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;


struct Segment
{
    int begin = 0, mid = 0, end = 0;
};


void input_segments(Segment *arr, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
        cin >> arr[i].mid;
}


void define_segments(Segment *arr, const size_t size, const int shift)
{
    for (size_t i = 0; i < size; ++i)
    {
        arr[i].begin = arr[i].mid - shift;
        arr[i].end = arr[i].mid + shift;
    }
}


bool compare_segments(Segment s1, Segment s2)
{
    if ((s1.begin >= s2.begin and s1.begin <= s2.end) or (s1.end >= s2.begin and s1.end <= s2.end))
        return true;

    return false;
}


int unique_numbers(Segment *arr, int size)
{
    int repeats = 0, ans;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i; j < size; ++j)
        {
            if (!(compare_segments(arr[i], arr[j]))) repeats++;
        }
    }
    ans = max(1, repeats / 2);
    return ans;
}


int main()
{
    int N, K;
    cin >> N >> K;
    auto *segments = new Segment[N];
    input_segments(segments, N);
    define_segments(segments, N, K);
    cout << unique_numbers(segments, N) << endl;
    delete[] segments;
    return 0;
}