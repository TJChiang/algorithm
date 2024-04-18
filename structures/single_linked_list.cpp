//
// Created by nature on 2024/4/4.
//

#include <iostream>
#include "single_linked_list.h"

namespace structures {
    SingleLinkedList::SingleLinkedList() {
        head = nullptr;
        size = 0;
    }

    SingleLinkedList::SingleLinkedList(const int val) {
        head = new LinkedNode(val);
        size = 1;
    }

    SingleLinkedList::SingleLinkedList(LinkedNode *root): size(0) {
        if (root == nullptr) return;

        head = root;
        const LinkedNode *cur = root;
        while (cur != nullptr) {
            size++;
            cur = cur->next;
        }
    }


    void SingleLinkedList::push_front(const int x) {
        head = new LinkedNode(x, head);
        size++;
    }

    void SingleLinkedList::push_back(const int x) {
        LinkedNode* newNode = new LinkedNode(x);
        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        LinkedNode* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void SingleLinkedList::insert(int index, const int val) {
        if (index > size) return;
        if (index < 0) index = 0;

        // 設定虛擬頭節點
        LinkedNode* dummy = new LinkedNode();
        dummy->next = head;
        LinkedNode* cur = dummy;
        while (index > 0) {
            cur = cur->next;
            index--;
        }
        LinkedNode* newNode = new LinkedNode(val, cur->next);
        cur->next = newNode;
        size++;
        head = dummy->next;
        delete dummy;
        // delete 釋放 dummy 該指針原本所指的記憶體，但 dummy 值並非 null 而是隨機值
        // 為避免 dummy 變成野指針，再多加 dummy = nullptr
        dummy = nullptr;
    }

    int SingleLinkedList::get(int index) {
        if (index < 0 || index >= size) return -1;

        const LinkedNode* cur = head;
        while (index > 0) {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void SingleLinkedList::remove(int index) {
        if (index < 0 || index >= size) return;

        // 設定虛擬頭節點
        LinkedNode* dummy = new LinkedNode();
        dummy->next = head;
        LinkedNode* cur = dummy;
        while (index > 0) {
            cur = cur->next;
            index--;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        head = dummy->next;
        delete dummy;
        // delete 釋放 dummy 該指針原本所指的記憶體，但 dummy 值並非 null 而是隨機值
        // 為避免 dummy 變成野指針，再多加 dummy = nullptr
        dummy = nullptr;
        delete temp;
        temp = nullptr;
        size--;
    }

    /**
     * 初始化 list 資料 & 移除 node
     */
    void SingleLinkedList::clear() {
        while (head != nullptr) {
            const LinkedNode* cur = head;
            head = head->next;
            delete cur;
            cur = nullptr;
        }
        size = 0;
    }

    void SingleLinkedList::reverse() {
        if (head == nullptr) return;

        LinkedNode* cur = head;
        LinkedNode* prev = nullptr;

        while (cur != nullptr) {
            LinkedNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    LinkedNode *SingleLinkedList::getRoot() {
        return this->head;
    }

    void SingleLinkedList::print() const {
        const LinkedNode* cur = head;
        if (cur == nullptr) {
            std::cout << "Empty Linked list.";
        }

        while (cur != nullptr) {
            std::cout << cur->val;
            if (cur->next != nullptr) std::cout << " -> ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

} // structures
