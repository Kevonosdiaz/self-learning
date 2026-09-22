def removeKthNodeFromEnd(head, k):
    # Write your code here
    curr_node = head
    copy = []
    while curr_node:
        copy.append(curr_node)
        curr_node = curr_node.next

    offset_pos = len(copy) - 1 - k
    if offset_pos < 0:
        return head

    if offset_pos == 0:
        head = head.next
    else:
        pred = copy[offset_pos - 1]
        if k == 0:
            pred.next = None
        else:
            pred.next = pred.next.next
    return head
