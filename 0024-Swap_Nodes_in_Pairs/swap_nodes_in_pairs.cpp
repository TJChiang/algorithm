#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;

        while (cur->next != NULL && cur->next->next != NULL) {
            ListNode* temp = cur->next;
            ListNode* temp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp;
            cur->next->next->next = temp1;

            cur = cur->next->next;
        }

        return dummy->next;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    ListNode* input = new ListNode(1);
    ListNode* cur = input;
    for (int i : {2, 3, 4}) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    ListNode* result = sol.swapPairs(input);

    while (result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }

    return 0;
}