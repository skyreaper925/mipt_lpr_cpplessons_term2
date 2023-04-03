// remove_key
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


void remove_key(Node*& head_ref, int key)
{
    if (head_ref == nullptr)
        return;

    Node* tmp1;

    if (head_ref->key == key)
    {
        tmp1 = head_ref->next;
        delete head_ref;
        head_ref = tmp1;
        return;
    }

    tmp1 = head_ref;
    Node* tmp2;
    while (tmp1->next != nullptr)
    {
        if ((tmp1->next)->key == key)
            break;

        tmp1 = tmp1->next;
    }

    if (tmp1->next == nullptr)
        return;

    tmp2 = (tmp1->next)->next;
    delete tmp1->next;
    tmp1->next = tmp2;
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