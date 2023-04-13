// reverse
#include <iostream>

using namespace std;


struct Node
{
    int name;
    Node *next;
};

void print_list(Node *head_ptr)
{
    if (head_ptr == nullptr)
        return;

    Node *tmp = head_ptr;
    while (tmp != nullptr)
    {
        std::cout << tmp->name << ' ';
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

    delete head_ptr;
}


void push_back(Node *&head_ref, int new_key)
{
    Node *node = new Node;
    Node *tmp = head_ref;
    node->name = new_key;
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


Node *read_list(Node *head)
{
    int key;
    while (std::cin >> key and key != 0)
        push_back(head, key);

    push_back(head, 0);
    return head;
}


Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


int main()
{
    Node *head = nullptr;
    head = read_list(head);
    head = reverse(head);
    print_list(head);
    destroy_list(head);
    return 0;
}