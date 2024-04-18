#include <iostream>
#include "../structures/linked_node.h"
#include "../structures/single_linked_list.h"

class Solution {
public:
    structures::LinkedNode* reverseList(structures::LinkedNode* head) {
        structures::LinkedNode* cur = head;
        structures::LinkedNode* prev = nullptr;

        while (cur != nullptr) {
            structures::LinkedNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};

void show_result(const structures::LinkedNode* root) {
    const structures::LinkedNode* cur = root;
    if (cur == nullptr) {
        std::cout << "Empty Linked list.";
    }

    std::cout << "result: ";
    while (cur != nullptr) {
        std::cout << cur->val;
        if (cur->next != nullptr) std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main() {
    auto list1 = structures::SingleLinkedList();
    for (int i = 1; i <= 5; i++) {
        list1.push_back(i);
    }
    std::cout << "list1: ";
    list1.print();

    auto* sol = new Solution();
    const auto* result1 = sol->reverseList(list1.getRoot());

    show_result(result1);
    return 0;
}
