// getLoopSize
#include <iostream>
#include <unordered_set>
#include <cassert>

using namespace std;

struct Node {
    Node *next = nullptr;
};

int getLoopSize(Node *startNode) {
    unordered_set<Node *> visited;
    auto curr = startNode;
    while (curr != nullptr) {
        if (visited.find(curr) != nullptr) {
            int length = 0;
            Node *start = curr;
            do {
                length++;
                curr = curr->next;
            } while (curr != start);
            return length;
        }
        visited.insert(curr);
        curr = curr->next;
    }
    return 0;
}

int main() {
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = head->next;
    assert((getLoopSize(head)) == 3);

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}
