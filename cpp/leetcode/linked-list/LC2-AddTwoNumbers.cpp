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
    // Idea 1: Reverse each list and read their numbers and generate a new LL
    l1 = reverse(l1);
    l2 = reverse(l2);
    std::vector<int> nums;

    // Add the sum of the linked lists and store in nums
    while (l1) {
      int sum = l1->val + l2->val;
      nums.push_back(sum);
      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode *dummy;
    ListNode *tail = dummy;
    // Iterate through nums and generate a new LL
    for (int i = 0; i < nums.size(); i++) {
      ListNode *node = new ListNode{nums[i], nullptr};
      node->next = tail->next;
      tail->next = node;
      tail = node->next;
    }

    // This should return the head of the new list
    return dummy->next;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *prev;
    ListNode *next;
    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};

// Newer version with small changes done on leetcode web

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Idea 1: Reverse each list and read their numbers and generate a new LL
    l1 = reverse(l1);
    l2 = reverse(l2);
    std::vector<int> nums;

    // Add the sum of the linked lists and store in nums
    while (l1) {
      int sum = l1->val + l2->val;
      nums.push_back(sum);
      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode *dummy;
    ListNode *tail = dummy;
    // Iterate through nums and generate a new LL
    for (int i = 0; i < nums.size(); i++) {
      ListNode *node = new ListNode{nums[i], nullptr};
      node->next = tail->next;
      tail->next = node;
      tail = node->next;
    }

    // This should return the head of the new list
    return dummy->next;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *next;
    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};
