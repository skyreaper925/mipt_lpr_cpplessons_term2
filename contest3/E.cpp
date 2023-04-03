// insert_after
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
    List* list = new List;
    list->NIL = new Node;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    list->size = 0;
    return list;
}


List* push_back(List* list_ptr, int new_key)
{
    Node* node = new Node;
    node->next = nullptr;
    node->prev = nullptr;
    node->key = new_key;
    if (list_ptr == nullptr)
    {
        list_ptr = create_empty_list();
        list_ptr->HEAD = node;
        list_ptr->TAIL = node;
        list_ptr->size = 1;
        return list_ptr;
    }

    else if ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL))
    {
        node->next = list_ptr->NIL;
        node->prev = list_ptr->NIL;
        list_ptr->HEAD = node;
        list_ptr->TAIL = node;
        list_ptr->size = 1;
        return list_ptr;
    }

    node->next = list_ptr->NIL; //maybe here should be created new special node for tail
    node->prev = list_ptr->TAIL;
    list_ptr->TAIL->next = node;
    list_ptr->TAIL = node;
    list_ptr->size++;
    return list_ptr;
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


List* insert_after(List* list_ptr, Node* prev_ptr, int new_key)
{
    if (list_ptr == nullptr or prev_ptr == list_ptr->NIL)
        return list_ptr;

    else //maybe here should be created new special node for prev->next
    {
        Node* node = new Node;
        node->key = new_key;
        node->prev = prev_ptr;
        node->next = prev_ptr->next;
        if (prev_ptr->next == list_ptr->NIL)
            list_ptr->TAIL = node;

        else
            prev_ptr->next->prev = node;

        prev_ptr->next = node;
        list_ptr->size++;
    }

    return list_ptr;
}


int main() {
    List* list = create_empty_list();
    list = push_back(list, 0);
    list = insert_after(list, list->HEAD, 1);
//    print_list(list->HEAD);
//    cout << list->HEAD->next->key << ' ' << list->TAIL->key;
    if ((list->HEAD->key == 0) and (list->TAIL->key == 1)) {
        cout << "OK" << endl;
    }
    delete list->HEAD;
    delete list->TAIL;
    delete list->NIL;
    delete list;
    return 0;
}