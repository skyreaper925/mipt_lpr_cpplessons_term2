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

void remove_key(Node*& head_ptr, int key)
{
    Node* curr = head_ptr;
    while (curr != nullptr)
    {
        if (curr->next != nullptr and (curr->next)->key == key)
        {
            auto tmp = curr->next;
            curr->next = tmp->next;
            delete tmp;
        }

        curr = curr->next;
    }

    delete curr;
}



int main() {
    Node* HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    remove_key(HEAD, 0);
    remove_key(HEAD, 1);
    remove_key(HEAD, 2);
    remove_key(HEAD, 3);
    if (HEAD == nullptr) {
        cout << "OK" << endl;
    }
    return 0;
}