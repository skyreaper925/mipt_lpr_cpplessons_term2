// intersection
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Street
{
    int x0, y0, x, y;
    int k, b;
};

bool intersection(Street s1, Street s2)
{
    int a1 = s1.y0 - s1.y;
    int b1 = s1.x - s1.x0;
    int c1 = s1.x0 * s1.y - s1.x * s1.y0;
    int a2 = s2.y0 - s2.y;
    int b2 = s2.x - s2.x0;
    int c2 = s2.x0 * s2.y - s2.x * s2.y0;
    double det = a1 * b2 - a2 * b1;
    if (det == 0)
        return false;

    double x2 = (b1 * c2 - b2 * c1) / det;
    if (x2 >= min(s1.x0, s1.x) && x2 <= max(s1.x0, s1.x) && x2 >= min(s2.x0, s2.x) && x2 <= max(s2.x0, s2.x))
        return true;

    return false;
}

bool onSegment(int x, int y, Street s)
{
    if (x <= max(s.x0, s.x) && x >= min(s.x0, s.x) && y <= max(s.y0, s.y) && y >= min(s.y0, s.y))
        return true;

    return false;
}

bool hardCase (Street s1, Street s2)
{
    int first0 = s1.k * s2.x0 - s2.y0 + s1.b;
    int first = s1.k * s2.x - s2.y + s1.b;
    int second0 = s2.k * s1.x0 - s1.y0 + s2.b;
    int second = s2.k * s1.x - s1.y + s2.b;

    if ((first == 0) and (first0 == 0) and (second0 == 0) and (second == 0))
    {
        if  (
                (onSegment(s1.x0, s1.y0, s2)) or
                (onSegment(s1.x, s1.y, s2)) or
                (onSegment(s2.x0, s2.y0, s1)) or
                (onSegment(s2.x, s2.y, s1))
                )
        {
            cout << "YES";
            return true;
        }
    }

    return false;
}

int main()
{
    int n = 2;
    struct Street streets[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> streets[i].x0 >> streets[i].y0 >> streets[i].x >> streets[i].y;
        if (streets[i].x - streets[i].x0)
            streets[i].k = (streets[i].y - streets[i].y0) / (streets[i].x - streets[i].x0);
        else
            streets[i].k = numeric_limits<int>::max();

        streets[i].b = streets[i].y0 - streets[i].k * streets[i].x0;
    }

    if (hardCase(streets[0], streets[1]))
        return 0;

    cout << ((intersection(streets[0], streets[1])) ? "YES" : "NO") << endl;
    return 0;
}
