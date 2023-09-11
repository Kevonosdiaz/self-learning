
// /**
//  * Definition for singly-linked list.
//  */
// // public class ListNode {
// //     int val;
// //     ListNode next;
// //     ListNode() {}
// //     ListNode(int val) { this.val = val; }
// //     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// // }
// class Solution {
//     public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
//         ListNode next1 = list1;
//         ListNode before1 = list1;
//         // If one of the lists is null, then return the other (if both are null, then that case it caught as well)
//         if (list1 == null) {
//             return list2;
//         }
//         else if (list2 == null) {
//             return list1;
//         }

//         // Merge the two
//         while (list2 != null) {
//             if (next1 == null) {
//                 ListNode temp = new ListNode(list2.val);
//                 temp.next = next1.next;
//                 next1.next = temp;
//                 // Traverse to next element of list2
//                 list2 = list2.next;
//             }
//             else if (list2.val < next1.val) {
//                 if (before1 != next1) {
//                     ListNode temp = new ListNode(list2.val);
//                     temp.next = next1;
//                     before1.next = temp;
//                     // Traverse to next element of list2
//                     list2 = list2.next;
//                     before1 = before1.next;
//                 }
//                 else {
//                     // Insert value of list2's node before current list 1 node
//                     ListNode temp = new ListNode(list2.val);
//                     temp.next = list1;
//                     list1 = temp;
//                     // Traverse to next element of list2
//                     list2 = list2.next;
//                     before1 = list1;
//                 }
//             }
//             else if (list2.val == next1.val) {
//                 // Insert directly in front
//                 ListNode temp = new ListNode(list2.val);
//                 temp.next = next1.next;
//                 next1.next = temp;
//                 // Traverse to next element of list2
//                 list2 = list2.next;
//             }
//             else if (next1.next == null) { // Just insert directly after next in this case
//                 if (next1.val < list2.val) {
//                     // Insert directly in front
//                     ListNode temp = new ListNode(list2.val);
//                     temp.next = next1.next;
//                     next1.next = temp;
//                     // Traverse to next element of list2
//                     list2 = list2.next;
//                 }
//                 else {
//                     if (before1 != next1) {
//                     ListNode temp = new ListNode(list2.val);
//                     temp.next = next1;
//                     before1.next = temp;
//                     // Traverse to next element of list2
//                     list2 = list2.next;
//                     before1 = before1.next;
//                     }
//                     else {
//                     // Insert value of list2's node before current list 1 node
//                     ListNode temp = new ListNode(list2.val);
//                     temp.next = list1;
//                     list1 = temp;
//                     // Traverse to next element of list2
//                     list2 = list2.next;
//                     before1 = list1;
//                     }
//                 }
//             }
//             else {
//                 //Check if the next value in list1 is also less than list2.val
//                 if (list2.val > next1.next.val) {
//                     // Set next to be the next element
//                     before1 = next1;
//                     next1 = next1.next;
//                 }
//                 else {
//                     // Insert directly in front
//                     ListNode temp = new ListNode(list2.val);
//                     temp.next = next1.next;
//                     next1.next = temp;
//                     // Traverse to next element of list2
//                     list2 = list2.next;
//                 }
//             }
                
//         }
//         return list1;
//     }
// }
