// mean point
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int mean;
};

int main()
{
    int n, s = 0;
    cin >> n;
    struct Student students[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> students[i].name >> students[i].mean;
        s += students[i].mean;
    }

    cout << s/n;
    return 0;
}