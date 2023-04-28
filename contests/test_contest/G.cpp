#include <iostream>
#include <cassert>

using namespace std;


struct Node
{
    int value{};
    Node *next = nullptr;
};


struct Stack
{
    Node *head = nullptr;
    size_t size = 0;
};


Stack stack_new()
{
    Stack new_stack;
    return new_stack;
}


bool stack_is_empty(Stack const &s)
{
    return (!s.size);
}


bool stack_is_full(Stack const &s)
{
    return (s.size == 100);
}


Stack &stack_push(Stack &s, int val)
{
    if (!stack_is_full(s))
    {
        Node *new_node = new Node{val, s.head};
        s.head = new_node;
        s.size++;
    }
    return s;
}


int stack_pop(Stack &s)
{
    int ans = 0;
    if (!stack_is_empty(s))
    {
        ans = s.head->value;
        auto tmp = s.head;
        s.head = s.head->next;
        delete tmp;
        s.size--;
    }
    return ans;
}


int main()
{
    Stack s = stack_new();
    assert(true == stack_is_empty(s));
    stack_push(s, -1);
    int expected = s.head->value;
    assert(false == stack_is_empty(s));
    assert(expected == stack_pop(s));
    assert(true == stack_is_empty(s));
    for (unsigned cnt = 0; cnt != 100; ++cnt)
        stack_push(s, 1);
    assert(true == stack_is_full(s));
    return 0;
}