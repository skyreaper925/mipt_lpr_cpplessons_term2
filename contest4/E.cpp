// different_brackets
#include <iostream>

using namespace std;


int main()
{
    char c = getchar(), last_c = '0';
    int opened = 0, closed = 0;
    while (c != '\n' and opened >= closed)
    {
        if (not(c == '(' or c == '<' or c == '[' or c == '{'))
        {
            if ((c == ')' and last_c != '(') or (c == '}' and last_c != '{') or (c == '>' and last_c != '<') or
                (c == ']' and last_c != '['))
            {
                cout << "NO" << endl;
                return 0;
            }

            closed++;
        }

        else
            opened++;

        last_c = c;
        c = getchar();
    }

    cout << ((opened == closed) ? "YES" : "NO") << endl;
    return 0;
}