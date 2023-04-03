// remove_key
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


void remove_key(List* list_ptr, int key)
{
    if (list_ptr == nullptr or ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL)))
        return;

    Node* curr = list_ptr->HEAD;
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            if (curr == list_ptr->HEAD)
            {
                list_ptr->HEAD = curr->next;
                (list_ptr->HEAD)->prev = list_ptr->NIL;
                delete curr;
                return;
            }

            if (curr == list_ptr->TAIL)
            {
                list_ptr->TAIL = curr->prev;
                (list_ptr->TAIL)->next = list_ptr->NIL;
                delete curr;
                return;
            }

            else if (curr != list_ptr->TAIL and curr->key == key)
            {
                Node* tmp = curr->next;
                tmp->prev = curr->prev;
                (curr->prev)->next = tmp;
                delete curr;
                return;
            }

        }

        curr = curr->next;
    }
}



int main() {
    List* list = create_empty_list();
    push_back(list, 0);
    push_back(list, 1);
    push_back(list, 2);
    remove_key(list, 2);
    if (list->TAIL->key == 1) {
        cout << "OK" << endl;
    }
    return 0;
}
