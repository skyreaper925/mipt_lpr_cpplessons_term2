#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
using namespace std;

struct Dislocation {
    int x{};
    int y{};
};

int main()
{
    int N = 1;
    const int num_measurements = 1;
    const int a_min = 3;
    const int a_max = 1000;
    const int num_steps = 100;

    ofstream file("C://Users/volod/CLionProjects/mipt_lpr_cpplessons_term2/lab3/1.txt");
    mt19937 rng;
    struct Dislocation dislocations[N];
    for (int b = 0; b < num_steps; b++)
    {
        int a = a_min + b * (a_max - a_min) / (num_steps - 1);
        for (int j = 0; j < num_measurements; j++)
        {
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            rng.seed(seed);
//            auto start = chrono::high_resolution_clock::now();
            uniform_int_distribution <int> distribution(0,a-1);
            uniform_int_distribution <int> dstr(0,4);

            dislocations[0].x = a/2;
            dislocations[0].y = a/2;

            int steps = 0;
            while (dislocations[0].x != 0 && dislocations[0].x != a
                    && dislocations[0].y != 0 && dislocations[0].y != a)
            {
                int d = dstr(rng), dx = 0, dy = 0;
                switch (d)
                {
                    case 0: dx = 1;
                    case 1: dx = -1;
                    case 2: dy = 1;
                    case 3: dy = -1;
                }

                dislocations[0].x += dx;
                dislocations[0].y += dy;
                steps++;
            }

            file << a << ' ' << steps << "\n";
        }
    }

    file << endl;
    file.close();
    return 0;
}