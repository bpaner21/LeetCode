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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode newHead(0);
        newHead.next = head;
        
        ListNode *first = &newHead, *second = &newHead;
        
        // create a gap of n nodes between first and second
        for (int i = 0; i <= n; ++i) {
            
            first = first->next;
        }
        
        // pass throught the list until first reaches the end
        while (first != nullptr) {
            
            first = first->next;
            second = second->next;
        }
        
        // delete the nth node from the end of the list
        ListNode* oldNode = second->next;
        second->next = oldNode->next;
        delete oldNode;
        
        return newHead.next;
    }
};