#include <iostream>
#include <cassert>

using namespace std;


struct JumpList
{
    JumpList *next, *jump;
    unsigned id;
};


void erase_jump_list(JumpList *head)
{
    if (nullptr == head) return;
    erase_jump_list(head->next);
    delete head;
}


JumpList *clone_jump_list(JumpList *head)
{
    //trivial case
    if (head == nullptr)
        return nullptr;

    //starting the bypass from the head to create new nodes after existing ones
    //our old list will both contain old and new list one node after one
    JumpList *curr = head;
    while (curr != nullptr) //checking if the node has attributes
    {
        //creating new node
        auto *newNode = new JumpList{curr->next, nullptr, curr->id};
        //changing the link to created node
        curr->next = newNode;
        //going to next node
        curr = newNode->next;
    }

    //starting the bypass from the head to create new list
    curr = head;
    while (curr != nullptr)
    {
        //changing the jump field for all nodes except head and last one
        if (curr->jump != nullptr)
            curr->next->jump = curr->jump->next;

        curr = curr->next->next;
    }
    curr = head;
    //changing the link in old list
    JumpList *newHead = head->next;
    //starting the bypass from the head delete old list
    while (curr != nullptr)
    {
        JumpList *temp = curr->next;
        curr->next = temp->next;
        if (temp->next != nullptr)
            temp->next = temp->next->next;

        curr = curr->next;
    }
    //all procedures done. We returning
    return newHead;
}


int main()
{
    auto *elements = new JumpList[6];
    elements[0] = JumpList{.next = &elements[1], .jump = &elements[3], .id = 1u};
    elements[1] = JumpList{.next = &elements[2], .jump = &elements[4], .id = 2u};
    elements[2] = JumpList{.next = &elements[3], .jump = &elements[5], .id = 3u};
    elements[3] = JumpList{.next = &elements[4], .jump = &elements[5], .id = 4u};
    elements[4] = JumpList{.next = &elements[5], .jump = nullptr, .id = 5u};
    elements[5] = JumpList{.next = nullptr, .jump = nullptr, .id = 6u};
    JumpList *clone = clone_jump_list(elements);

    JumpList *a = elements, *b = clone;
    while (nullptr != a)
    {
        assert(a->id == b->id and a != b);
        if (nullptr != a->jump)
            assert(a->jump->id == b->jump->id and a->jump != b->jump);
        a = a->next;
        b = b->next;
    }
    assert(nullptr == b);
    delete[] elements;
    erase_jump_list(clone);
    return 0;
}
