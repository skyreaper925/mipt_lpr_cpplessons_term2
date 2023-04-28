// brackets
#include <iostream>

using namespace std;


int main()
{
    char c = getchar();
    int opened = 0, closed = 0;
    while (c != '\n' and opened >= closed)
    {
        if (c == '(')
            opened++;
        else if (c == ')')
            closed++;

        c = getchar();
    }

    cout << ((opened == closed) ? "YES" : "NO") << endl;
    return 0;
}