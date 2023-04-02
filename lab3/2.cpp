#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
using namespace std;

struct Dislocation {
    int x{};
    int y{};
    bool stopped = false;
};

int main()
{
    const int a_min = 3;
    const int num_steps = 100;

    ofstream file("C://Users/volod/CLionProjects/mipt_lpr_cpplessons_term2/lab3/2.txt");
    mt19937 rng;
    for (int b = 0; b < num_steps; b++)
    {
        int a = (b+1) * a_min, N = a/3;
        struct Dislocation dislocations[N];
        for (int j = 1; j <= N; j++)
        {
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            rng.seed(seed);
//            auto start = chrono::high_resolution_clock::now();
            uniform_int_distribution <int> distribution(0,a-1);
            uniform_int_distribution <int> dstr(0,4);

            for (int k = 0; k < j; ++k)
            {
                dislocations[k].x = distribution(rng);
                dislocations[k].y = distribution(rng);
//                cout << dislocations[k].x << " " << dislocations[k].y << endl;
            }

            bool all_stopped = false;
            int steps = 0;
            while (!all_stopped)
            {
                all_stopped = true;
                for (int i = 0; i < j; ++i)
                {
                    if (dislocations[i].stopped)
                        continue;

                    int d = dstr(rng), dx = 0, dy = 0;
                    switch (d)
                    {
                        case 0: dx = 1;
                        case 1: dx = -1;
                        case 2: dy = 1;
                        case 3: dy = -1;
                    }

                    if (dislocations[i].x + dx < 0 || dislocations[i].x + dx >= a
                        || dislocations[i].y + dy < 0 || dislocations[i].y + dy >= a)
                        dislocations[i].stopped = true;

                    else
                    {
                        bool collision = false;
                        for (int c = 0; c < j; ++c)
                        {
                            if (i == c || dislocations[c].stopped)
                                continue;

                            if (dislocations[i].x + dx == dislocations[c].x && dislocations[i].y + dy == dislocations[c].y)
                            {
                                if (dx == 0 || dy == 0)
                                    dislocations[c].stopped = true;

                                else
                                    collision = true;

                                break;
                            }
                        }

                        if (!collision)
                        {
                            dislocations[i].x += dx;
                            dislocations[i].y += dy;
                            steps++;
                        }
                    }

                    all_stopped &= dislocations[i].stopped;
                }
            }

            file << a << ' ' <<  j << ' ' << steps << "\n";
        }
    }

    file.close();
    return 0;
}