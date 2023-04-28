// print_list
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

void print_list(Node* head_ptr)
{
    while (head_ptr != nullptr)
    {
        std::cout << head_ptr->key << ' ';
        head_ptr = head_ptr->next;
    }

    std::cout << std::endl;
}

int main() {
    Node* HEAD = nullptr;
    push_back(HEAD, 0);
    push_back(HEAD, 1);
    push_back(HEAD, 2);
    print_list(HEAD);
    remove(HEAD);
    return 0;
}