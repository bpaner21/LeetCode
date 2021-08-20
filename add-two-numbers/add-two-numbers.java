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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        ListNode tempHead = new ListNode(-1);
        
        addLists(l1, l2, tempHead, 0);
        
        return tempHead.next;
    }
    
    private void addLists(ListNode l1, ListNode l2, ListNode prev, int carry) {
        
        // if both lists have been traversed, check if there is still a digit to carry over
        if (l1 == null && l2 == null) {
            
            if (carry == 0) { return; }
            
            ListNode temp = new ListNode(carry);
            
            prev.next = temp;
            
            return;
        }
        
        int sum = 0, remainder = 0;
        
        ListNode temp = new ListNode(0);
        
        prev.next = temp;
        
        // if either list has been fully traversed, add the remaining values and any digits that carry over
        if (l1 == null) {
            
            sum = l2.val + carry;
            
            temp.val = sum % 10;
            
            addLists(null, l2.next, temp, sum / 10);
            
            return;
        }
        
        if (l2 == null) {
            
            sum = l1.val + carry;
            
            temp.val = sum % 10;
            
            addLists(l1.next, null, temp, sum / 10);
            
            return;
        }
        
        // if neither list has been fully traversed, add and continue
        
        sum = l1.val + l2.val + carry;
            
        temp.val = sum % 10;
            
        addLists(l1.next, l2.next, temp, sum / 10);
            
        return;
    }
}