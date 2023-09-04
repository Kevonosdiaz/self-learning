package leetcode

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// Iterative approach
func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	var next *ListNode
	for head != nil {
		next = head.Next
		head.Next = prev
		prev = head
		head = next
	}

	return prev
}
