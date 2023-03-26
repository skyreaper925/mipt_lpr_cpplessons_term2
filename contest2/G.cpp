// find
#include <iostream>
using namespace std;

struct Node
{
    int key = 0;
    Node* next = nullptr;
};

void push_back(Node*& head_ref, int new_key)
{
    Node* node = new Node;
    Node* tmp = head_ref;
    node->key = new_key;
    node->next = nullptr;
    if (head_ref == nullptr)
    {
        head_ref = node;
        return;
    }

    while (tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = node;

}

void remove(Node*& node_ref)
{
    if (node_ref != nullptr)
    {
        auto tmp = node_ref;
        node_ref = node_ref->next;
        delete tmp;
    }
}

Node* find(Node* head_ref, int key)
{
    Node* curr = head_ref;
    while (curr != nullptr)
    {
        if (curr->key == key)
            return curr;

        curr = curr->next;
    }

    return nullptr;
}

using std::cout;
using std::endl;

int main() {
    Node* HEAD = nullptr, *current = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    find(HEAD, 2);
    if (current->key == 2) {
        cout << "OK" << endl;
    }
    return 0;
}