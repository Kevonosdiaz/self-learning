// LC2: Add Two Numbers

#include <iostream>
#include <string>
#include <vector>

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummyHead = ListNode(0);
    ListNode *tail = &dummyHead;
    bool carry = 0;

    while (l1 || l2 || carry != 0) {
      // Perform addition
      int digit1 = l1 ? l1->val : 0;
      int digit2 = l2 ? l2->val : 0;

      int sum = digit1 + digit2 + carry;

      // Determine which number (0-9) to store at node
      int num = sum % 10;
      carry = sum / 10;

      // Construct new node and append it
      ListNode *node = new ListNode(num);
      tail->next = node;
      tail = tail->next;

      // Update pointers
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    return dummyHead.next;
  }
};
