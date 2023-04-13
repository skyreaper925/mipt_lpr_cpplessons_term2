// poland
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int v, Node *n = nullptr) : value(v), next(n)
    {}
};


int evaluate(const string &expr)
{
    Node *head = nullptr;
    int i = expr.size() - 1;
    while (i >= 0)
    {
        if (isdigit(expr[i]))
        {
            int j = i;
            while (j >= 0 && isdigit(expr[j]))
                --j;
            int value = stoi(expr.substr(j + 1, i - j));
            head = new Node(value, head);
            i = j;
        }
        else if (expr[i] == '+' or expr[i] == '*')
        {
            int a = head->value;
            head = head->next;
            int b = head->value;
            head = head->next;
            int result;
            switch (expr[i])
            {
                case '+':
                    result = a + b;
                    break;
                case '*':
                    result = a * b;
                    break;
            }
            head = new Node(result, head);
        }
        --i;
    }
    int result = head->value;
    delete head;
    return result;
}


int main()
{
    string expr;
    getline(cin, expr);
    cout << evaluate(expr) << endl;
    return 0;
}