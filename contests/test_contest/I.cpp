#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool compare_segments(pair<int, int> a, pair<int, int> b)
{
    return a.second <= b.first;
}

int unique_numbers(int n, int k, int a[])
{
    sort(a, a + n);
    set<int> possible_values;
    for (int i = 0; i < n; i++)
    {
        int min_value = max(a[i] - k, 0);
        int max_value = a[i] + k;
        for (int j = min_value; j <= max_value; j++)
        {
            if (j >= a[i] - k && j <= a[i] + k)
            {
                possible_values.insert(j);
            }
        }
    }
    int count = 0;
    vector<pair<int, int>> segments;
    for (int value: possible_values)
    {
        if (segments.empty() || segments.back().second < value)
        {
            segments.push_back(make_pair(value, value));
            count++;
        }
        else
        {
            segments.back().second = value;
        }
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << unique_numbers(n, k, a) << endl;
    return 0;
}
