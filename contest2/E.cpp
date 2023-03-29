// destroy_list
#include <iostream>
#include <string>
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

void destroy_list(Node*& head_ref)
{
    while (head_ref != nullptr)
    {
        auto tmp = head_ref;
        head_ref = head_ref->next;
        delete tmp;
    }
}

int main() {
    Node* HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    destroy_list(HEAD);
    if (HEAD == nullptr) {
        cout << "OK" << endl;
    }

    return 0;
}