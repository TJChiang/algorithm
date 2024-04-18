#ifndef LEETCODE_EXERCISE_SINGLE_LINKED_LIST_H
#define LEETCODE_EXERCISE_SINGLE_LINKED_LIST_H
#include "linked_node.h"

namespace structures {

    class SingleLinkedList {
    private:
        int size;
        LinkedNode* head;
    public:
        SingleLinkedList();
        explicit SingleLinkedList(int val);
        explicit SingleLinkedList(LinkedNode* root);
        void push_front(int x);
        void push_back(int x);
        void insert(int index, int val);
        int get(int index);
        void remove(int index);
        void clear();
        void reverse();
        LinkedNode *getRoot();
        void print() const;
    };

} // structures

#endif
