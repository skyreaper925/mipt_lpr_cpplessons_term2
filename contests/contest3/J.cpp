// find_key
#include <iostream>
using namespace std;

struct Node
{
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = 0;
};


struct List
{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};
List* create_empty_list()
{
    List* list = new List{nullptr, nullptr, nullptr, 0};
    return list;
}


List* push_back(List* list_ptr, int new_key)
{
    Node* node = new Node{nullptr, nullptr, new_key};
    if (list_ptr == nullptr)
    {
        List* list_ptr = new List{node, node, nullptr, 1};
        return list_ptr;
    }

    node->next = nullptr; //maybe here should be created new special node for tail
    node->prev = list_ptr->TAIL;
    list_ptr->TAIL = node;
    list_ptr->size++;
    return list_ptr;
}


void destroy_list(List* list_ptr)
{
    if (list_ptr == nullptr)
        return;

    auto curr = list_ptr->HEAD;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        delete curr->prev;
    }

    delete curr;
    delete list_ptr->NIL;
    list_ptr->size = 0;
    delete list_ptr;
}


Node* find_key(List* list_ptr, int key)
{
    Node* curr = list_ptr->HEAD;
    while (curr != nullptr)
    {
        if (curr->key == key)
            return curr;

        curr = curr->next;
    }

    return list_ptr->NIL;
}


int main() {
    List* list = create_empty_list();
    Node* ptr = nullptr;
    push_back(list, 0);
    push_back(list, 1);
    push_back(list, 2);
    ptr = find_key(list, 2);
    if (ptr == list->TAIL) {
        cout << "OK" << endl;
    }
    destroy_list(list);
    return 0;
}
