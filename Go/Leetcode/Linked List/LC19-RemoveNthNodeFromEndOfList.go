package leetcode

// Definition for singly-linked list.
type ListNode struct {
    Val int
    Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
    // use slow and fast ptr method to find (n-1)st node, where fast is n nodes offset 
    offset := head
    slow := head

    for n > 0 {
        offset = offset.Next
        n--
    }

    // catch edge case where n is the size of the whole list
    if offset == nil {
        return head.Next
    }

    // shift both until slow is at (n-1)st node
    for offset.Next != nil {
        offset = offset.Next
        slow = slow.Next
    }

    // perform deletion
    slow.Next = slow.Next.Next

    return head
}


