// LC206: Reverse Linked List


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Recursive approach (see Go solution for iterative approach that should be faster and more space efficient)
    ListNode* reverseList(ListNode* head) {
        return reverseListHelp(head, nullptr);
    }

    ListNode* reverseListHelp(ListNode* head, ListNode* prev) {
        // Idea: Reverse direction by using a prev and next node, until we reach the last node
        if (!head) return prev;
        ListNode* next = head->next;
        head->next = prev;
        // head becomes the new previous
        return reverseListHelp(next, head);
    }
};