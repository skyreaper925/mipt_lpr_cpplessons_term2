// Flavius_problem
#include <iostream>

using namespace std;

struct Node
{
    char name;
    Node *next = nullptr;
    bool alive = true;
};


struct List
{
    Node *HEAD = nullptr;
    Node *TAIL = nullptr;
    Node *NIL = nullptr;
};


List *create_empty_list()
{
    List *list = new List;
    list->NIL = new Node;
    list->HEAD = list->NIL;
    list->TAIL = list->NIL;
    return list;
}


List *push_back(List *list_ptr, char new_name)
{
    Node *node = new Node;
    node->next = nullptr;
    node->name = new_name;
    if (list_ptr == nullptr)
    {
        list_ptr = create_empty_list();
        list_ptr->HEAD = node;
        list_ptr->TAIL = node;
        return list_ptr;
    }

    else if ((list_ptr->HEAD == list_ptr->NIL) and (list_ptr->TAIL == list_ptr->NIL))
    {
        node->next = list_ptr->NIL;
        list_ptr->HEAD = node;
        list_ptr->TAIL = node;
        return list_ptr;
    }

    node->next = list_ptr->NIL; //maybe here should be created new special node for tail
    list_ptr->TAIL->next = node;
    list_ptr->TAIL = node;
    return list_ptr;
}


void destroy_list(List *list_ptr)
{
    if (list_ptr == nullptr)
        return;

    Node *curr = list_ptr->HEAD;
    while (curr->next != nullptr)
    {
        Node *tmp = curr;
        curr = curr->next;
        delete tmp;
    }

    delete list_ptr->NIL;
    delete list_ptr;
}


int flavius(List *list_ptr, char target_name, int k)
{
    Node *curr = list_ptr->HEAD;
    int move = 1;
    while (curr->name != target_name or move % k)
    {
        if (curr->alive)
        {
            if (!(move % k))
            {
                curr->alive = false;
                move++;
                if (curr == list_ptr->TAIL)
                    curr = list_ptr->HEAD;
                else
                    curr = curr->next;
            }
            else
            {
                move++;
                if (curr == list_ptr->TAIL)
                    curr = list_ptr->HEAD;
                else
                    curr = curr->next;
            }
        }
        else
        {
            if (curr == list_ptr->TAIL)
                curr = list_ptr->HEAD;
            else
                curr = curr->next;
        }
    }
    return move / k;
}

int main()
{
    int n, k;
    char target, name;
    cin >> n;
    List *list = create_empty_list();
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        list = push_back(list, name);
    }
    cin >> k;
    cin >> target;
    cout << flavius(list, target, k) << endl;
    destroy_list(list);
    return 0;
}
