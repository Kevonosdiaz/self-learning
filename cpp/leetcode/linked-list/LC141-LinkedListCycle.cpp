// LC141: Linked List Cycle

#include <limits.h>

// Definition for singly-linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        /*
         * hasCycle returns true is the linked list has a cycle in it
         * Otherwise, it returns false
        */
        bool hasCycle_Fast(ListNode *head) {
            // My initial approach with O(n) time, O(n) memory:
            // One pass of the LL, so it is fast

            // One way to do this with low, but O(n) memory is to mark the values of visited nodes
            // We could do this by taking advantage of the constraints, using INT_MAX, 100001, etc. which will not show up
            
            while (head) {
                if (head->val == INT_MAX) return true;
                head->val = INT_MAX;
                head = head->next;
            }

            return false;
        }

        bool hasCycle_Small(ListNode *head) {
            // An approach with O(n) time and O(1) memory:
            // This approach can loop through multiple times, but retains O(n) time still

            // Fast and slow pointer method
            // Either the fast ptr laps slow (true), or reaches an end (false)
            
            ListNode *slow = head;
            ListNode *fast = head;

            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
                if (fast == slow) return true;
            }

            return false;
        }
}
