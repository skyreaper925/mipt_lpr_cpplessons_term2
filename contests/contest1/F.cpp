// Комплексное умножение
#include <iostream>
using namespace std;

struct Complex {
    int re = 0;
    int im = 0;
};

Complex complexMul(const Complex& lhs, const Complex& rhs)
{
    Complex result;
    result.re = lhs.re * rhs.re - lhs.im * rhs.im;
    result.im = lhs.im * rhs.re + lhs.re * rhs.im;
    return result;
}

int main()
{
    int n = 2;
    Complex result, curr, tmp;
    cin >> curr.re >> curr.im;
    for (int j = 0; j < n-1; ++j)
    {
        cin >> tmp.re >> tmp.im;
        result = complexMul(curr, tmp);
        curr = result;
    }

    cout << result.re << ' ' << result.im;
    return 0;
}