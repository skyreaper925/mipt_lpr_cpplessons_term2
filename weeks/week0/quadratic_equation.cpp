// Qudratic equation
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    float x1, x2;
    cin >> a >> b >> c;
    // cout << a << " " << b << " " << c << endl;
    if (a == 0)
    {
        x1 = -c/b;
        x2 = x1;
    }

    else
    {
        float D = pow(b, 2) - (4*a*c);
        cout << D << endl;
        if (D < 0)
        {
            cout << "Решений нет";
            return 0;
        }

        else if (D == 0)
        {
            x1 = -b / (2*a);
            x2 = x1;
        }
        else
        {
            x1 = (-b + sqrt(D)) / (2*a);
            x2 = (-b - sqrt(D)) / (2*a);
        }

    }

    cout << x1 << " " << x2 << endl;
    return 0;
}