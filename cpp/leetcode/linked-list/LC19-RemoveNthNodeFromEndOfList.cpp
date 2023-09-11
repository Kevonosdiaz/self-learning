// LC19: Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Use 1 ptr to get (n-1) offset from head and another to get (n-1)st position
        // by advancing both pointers until the 1st ptr reaches null
        ListNode* offset = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++) {
            offset = offset->next;
        }

        if (!offset) return head->next; // If n == head.size, just return tail of list

        while (offset->next) {
            offset = offset->next;
            slow = slow->next;
        }

        // Perform deletion (constant time)
        slow->next = slow->next->next;

        return head;
    }
};