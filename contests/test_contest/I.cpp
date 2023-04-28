// unique numbers
#include <iostream>
#include "cassert"

using namespace std;


const int MAX_SIZE = 100;


struct Stack
{
    int data[MAX_SIZE];
    int top;
};

Stack stack_new()
{
    Stack stack;
    stack.top = -1;
    return stack;
}


bool stack_is_full(Stack const &stack)
{
    return stack.top == MAX_SIZE - 1;
}


Stack &stack_push(Stack &stack, int val)
{
    if (stack_is_full(stack))
    {
        throw std::overflow_error("Stack is full");
    }
    stack.data[++stack.top] = val;
    return stack;
}


bool stack_is_empty(Stack const &stack)
{
    return stack.top == -1;
}


int stack_pop(Stack &stack)
{
    if (stack_is_empty(stack))
    {
        throw std::underflow_error("Stack is empty");
    }
    return stack.data[stack.top--];
}


int main()
{
    Stack s = stack_new();
    assert(true == stack_is_empty(s));
    stack_push(s, -1);
    int expected = s.top;
    assert(false == stack_is_empty(s));
    assert(expected == stack_pop(s));
    assert(true == stack_is_empty(s));
    for (unsigned cnt = 0; cnt != 100; ++cnt)
        stack_push(s, 1);
    assert(true == stack_is_full(s));
    return 0;
}