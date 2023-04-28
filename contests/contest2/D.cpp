// insert_after
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int key = 0;
    Node* next = nullptr;
};

void insert_after(Node*& prev_ref, int new_key)
{
    if (prev_ref == nullptr)
        return;

    Node* node = new Node{new_key, nullptr};
    node->next = prev_ref->next;
    prev_ref->next = node;
}

int main() {
    Node* HEAD = new Node;
    insert_after(HEAD, 0);
    insert_after(HEAD, 1);
    insert_after(HEAD, 2);
    Node* ptr = HEAD;
    while (ptr->next != nullptr) {
        cout << ptr->key << ' ';
        ptr = ptr->next;
    }
    cout << ptr->key << endl;
    ptr = HEAD;
    while (ptr->next != nullptr) {
        ptr = HEAD->next;
        delete HEAD;
        HEAD = ptr;
    }
    delete HEAD;
    return 0;
}
