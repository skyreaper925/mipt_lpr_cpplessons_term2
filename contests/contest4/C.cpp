// mergeTwoLists
#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node *next;
};


void push_front(Node *&head_ref, int new_key)
{
    Node *node = new Node;
    node->data = new_key;
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


void print_list(Node *head_ptr)
{
    if (head_ptr == nullptr)
        return;

    Node *tmp = head_ptr;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << ' ';
        tmp = tmp->next;
    }

    std::cout << std::endl;
}


Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Node *curr1 = list1, *curr2 = list2, *curr, *head;
    if (curr1->data < curr2->data)
    {
        curr = curr1;
        curr1 = curr1->next;
    }
    else
    {
        curr = curr2;
        curr2 = curr2->next;
    }

    head = curr;
    while (curr1 != nullptr and curr2 != nullptr)
    {
        if (curr1->data < curr2->data)
        {
            curr->next = curr1;
            curr1 = curr1->next;
        }
        else
        {
            curr->next = curr2;
            curr2 = curr2->next;
        }

        curr = curr->next;
    }

    if (curr1 == nullptr)
        curr->next = curr2;

    else if (curr2 == nullptr)
        curr->next = curr1;

    return head;
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
    Node *list1 = nullptr, *list2 = nullptr;
    list1 = read_list(list1);
    list2 = read_list(list2);
    print_list(list1);
    print_list(list2);
    Node *list3 = mergeTwoLists(list1, list2);
    print_list(list3);
    destroy_list(list3);
    return 0;
}