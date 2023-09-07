// LC143: Reorder List

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
		// Reorder so that it goes L0 -> Ln -> L1 -> L(n-1) ... until they meet
		void reorderList(ListNode* head) {
			if (!head || !head->next) {
				return; // Already in correct ordering
			}
			// Use fast & slow ptr method to get the middle
			ListNode* slow = head;
			ListNode* fast = head->next;
			
			while (fast && fast->next) {
				slow = slow->next;
				fast = fast->next->next;
			}
			
			ListNode* second = slow->next;
			slow->next = nullptr; // end of the final list
			ListNode* prev = nullptr;

			// Reverse the second half
			while (second) {
				ListNode* tmp = second->next;
				second->next = prev;
				prev = second;
				second = tmp;
			}

			// Merge the halves together
			ListNode* first = head;
			second = prev;
			while (second) {
				ListNode* tmp1 = first->next;
				ListNode* tmp2 = second->next;
				first->next = second;
				second->next = tmp1;
				first = tmp1, second = tmp2;
			}
		}
};


