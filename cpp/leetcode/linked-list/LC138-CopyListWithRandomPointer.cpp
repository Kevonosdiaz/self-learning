// LC138: Copy List with Random Pointer


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Attempt interweaving (O(1) space) method:
            // Add new node copies directly after the original node
            // Shift random ptrs and make use of copy position
            // to get every 2nd node into a separate list and return
        if (!head) return nullptr;
        Node* iter = head;

        // Add interweaving copies
        while (iter) {
            Node* copy = new Node(iter->val);
            copy->next = iter->next;
            iter->next = copy;
            iter = copy->next;
        }

        iter = head;

        // Set random field for new nodes
        while (iter) {
            if (iter->random) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        // Copy the copied list head (head.next)
        Node* res = head->next;
        iter = res;

        // Link new nodes and relink old nodes
        while (head) {
            head->next = head->next->next;
            if (iter && iter->next) {
                iter->next = iter->next->next;
            } else {
                iter->next = nullptr;
            }
        

            iter = iter->next;
            head = head->next;
        }
        return res;
    }
};