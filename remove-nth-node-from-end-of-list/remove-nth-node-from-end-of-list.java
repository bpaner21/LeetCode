/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        
        ListNode first = newHead, second = newHead;
        
        // create a gap of n nodes between first and second
        for (int i = 0; i <= n; ++i) {
            
            first = first.next;
        }
        
        // pass throught the list until first reaches the end
        while (first != null) {
            
            first = first.next;
            second = second.next;
        }
        
        // delete the nth node from the end of the list
        second.next = second.next.next;
        
        return newHead.next;
    }
}