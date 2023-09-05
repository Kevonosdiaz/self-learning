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
			// Since we have a singly-linked list we can't use two pointers and alternate them directly
			// We could use an external DS such as an array, vector, or stack to arrange the nodes
			// We need to have the second nodes always be the nth nodes, so depending on if n is even
			// or odd, we may want all even or all odd nodes stored together (?)o
		}
}
