// Node realisation
#include <iostream>
using namespace std;


struct Node
{
    int key = 0;
    Node* next = nullptr;
};


int main() {
    Node *HEAD = new Node;
    if ((HEAD->key == 0) and (HEAD->next == nullptr)) {
        cout << "OK" << endl;
    } else {
        cout << endl;
    }
    delete HEAD;
    return 0;
}