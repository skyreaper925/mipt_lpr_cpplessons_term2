// find_middle
#include <iostream>

using namespace std;


struct Node
{
    int value;
    Node *next;
};


void push_front(Node *&head_ref, int new_key)
{
    Node *node = new Node;
    node->value = new_key;
    node->next = head_ref;
    head_ref = node;
}


Node *read_list(Node *head)
{
    int key;
    while (std::cin >> key and key != 0)
        push_front(head, key);

    return head;
}


int find_middle(const Node *head)
{
    const Node *curr = head;
    int n = 0;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        n++;
    }

    n++;
    curr = head;
    for (int i = 0; i < n / 2; ++i)
    {
        curr = curr->next;
    }

    return curr->value;
}


void print_list(Node *head_ptr)
{
    if (head_ptr == nullptr)
        return;

    Node *tmp = head_ptr;
    while (tmp != nullptr)
    {
        std::cout << tmp->value << ' ';
        tmp = tmp->next;
    }

    std::cout << std::endl;
}


void destroy_list(Node *head_ptr)
{
    if (head_ptr == nullptr)
        return;

    Node *curr = head_ptr;
    while (curr->next != nullptr)
    {
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}


int main()
{
    Node *head = nullptr;
    head = read_list(head);
    print_list(head);
    cout << find_middle(head) << endl;
    destroy_list(head);
    return 0;
}