// push_front
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node* &head_ref, int new_key)
//    Функция добавляет узел в начало списка и перемещает указатель head_ref на данный узел
{
    Node* node = new Node;
    node->key = new_key;
    node->next = head_ref;
    head_ref = node;
}


int main() {
    Node* HEAD = nullptr;
    push_front(HEAD, 2);
    push_front(HEAD, 1);
    push_front(HEAD, 0);
    Node* ptr = HEAD;
    while (ptr->next != nullptr) {
        cout << ptr->key << ' ';
        ptr = ptr->next;
    }
    cout << ptr->key << endl;
    ptr = HEAD;
    while (ptr->next != nullptr) {
        ptr = HEAD->next;
        delete HEAD;
        HEAD = ptr;
    }
    delete HEAD;
    return 0;
}