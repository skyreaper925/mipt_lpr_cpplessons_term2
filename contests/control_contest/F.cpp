//wagons and bars
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, L;
    cin >> N;
    vector<long long> wagons(N + 1, 0), sum(N + 1, 0);
    //summing all wagons to find out their number
    for (int i = 1; i <= N; ++i)
    {
        cin >> wagons[i];
        sum[i] = sum[i - 1] + wagons[i];
    }
    cin >> L;
    //trivial case. "all in the furnace"
    if (sum[N] < L)
    {
        cout << N << endl;
        return 0;
    }
    //not trivial case. minimizing the wagon number
    int left = 1, right = N, ans = N;
    while (left <= right)
    {
        //starting bin search
        int mid = (left + right) / 2;
        bool flag = false;
        for (int i = mid; i <= N; ++i)
        {
            //decomposition in sorted arr by two indexes
            if (sum[i] - sum[i - mid] >= L)
            {
                flag = true;
                break;
            }
        }
        //if we have new solution
        if (flag)
        {
            ans = mid;
            right = mid - 1;
        }
            //otherwise we continue the search
        else
            left = mid + 1;
    }
    cout << ans << endl;
    return 0;
}