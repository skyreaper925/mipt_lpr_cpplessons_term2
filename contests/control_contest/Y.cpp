#include <iostream>
#include <unordered_set>

using namespace std;

const size_t i = 2;

int main() {
    const size_t size = 3;
    int a[size]{0};
    int *b = new int[size]{1};
    auto c = new int[size]{2};
    for (size_t i = 0; i < size; ++i) {
        cout << "a " << a[i] << " i_local " << i << " i_global " << ::i << " b " << b[i] << " c " << c[i] << endl;

    }
    cout << i << endl;
    return 0;
}
