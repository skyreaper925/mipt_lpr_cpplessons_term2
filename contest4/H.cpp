#include <iostream>

using namespace std;

int main()
{
    int s = 0, e = 0;
    char vr[100], stack[100], exit[100];
    cin >> vr;
    for (int i = 0; vr[i] != '\n'; i++)
        switch (vr[i])
        {
            case '+':
                while ((s != 0) && (stack[s - 1] != '('))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '+';
                s++;
                break;

            case '-':
                while ((s != 0) && (stack[s - 1] != '('))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '-';
                s++;
                break;
            case '*':
                while ((s != 0) && (stack[s - 1] != '(') && (stack[s - 1] != '+') && (stack[s - 1] != '-'))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '*';
                s++;
                break;
            case '/':
                while ((s != 0) && (stack[s - 1] != '(') && (stack[s - 1] != '+') && (stack[s - 1] != '-'))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s] = '/';
                s++;
                break;
            case '(':
            {
                stack[s] = '(';
                s++;
                break;
            }
            case ')':

                while ((stack[s - 1] != '(') && (s != 0))
                {
                    exit[e] = stack[s - 1];
                    e++;
                    s--;
                }
                stack[s - 1] = ' ';
                s--;
                break;


            default:
            {
                exit[e] = vr[i];
                e++;
                if ((vr[i + 1] == '+') ||
                    (vr[i + 1] == '-') ||
                    (vr[i + 1] == '*') ||
                    (vr[i + 1] == '/') ||
                    (vr[i + 1] == '(') ||
                    (vr[i + 1] == ')'))
                {
                    exit[e] = ' ';
                    e++;
                }
            }
        }

    exit[e] = ' ';
    e++;
    while (s != 0)
    {
        exit[e] = stack[s - 1];
        e++;
        s--;
    }
    exit[e] = ' ';
    for (int i = 0; i < e; i++)
    {
        cout << exit[i];
    }
}