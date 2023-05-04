// banandw
#include <iostream>
#include <algorithm>

using namespace std;


string lcs(const string &s1, const string &s2)
{
    const size_t n = s1.length();
    const size_t m = s2.length();
    auto table = new int *[n + 1];
    for (size_t i = 0; i < n + 1; ++i)
        table[i] = new int[m + 1];

    for (size_t i = 0; i <= n; ++i)
    {
        for (size_t j = 0; j <= m; ++j)
        {
            if (i == 0 or j == 0)
                table[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;

            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    string result = "";
    size_t i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            result += s1[i - 1];
            --i;
            --j;
        }
        else if (table[i - 1][j] > table[i][j - 1])
            --i;

        else
            --j;
    }
    for (i = 0; i < n + 1; ++i)
        delete[] table[i];

    delete[] table;
    return result;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    double frac = static_cast<double>(lcs(s1, s2).length()) / min(s1.length(), s2.length());
    int ans = static_cast<int>(frac * 100);
    cout << ans << endl;
    return 0;
}