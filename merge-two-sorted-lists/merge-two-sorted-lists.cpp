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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == nullptr) { return l2; }
        if (l2 == nullptr) { return l1; }
        
        ListNode newHead, *temp = &newHead;
        
        while (l1 != nullptr && l2 != nullptr) {
            
            if (l1->val <= l2->val) {
                
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                
                temp->next = l2;
                l2 = l2->next;
            }
            
            temp = temp->next;
        }
        
        temp->next = (l1 != nullptr) ? l1 : l2; 
        
        return newHead.next;
    }
};