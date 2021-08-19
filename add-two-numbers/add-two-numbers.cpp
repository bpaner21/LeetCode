/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* tempHead = new ListNode(0);
        
        addLists(l1, l2, tempHead, 0);
        
        return(tempHead->next);
    }
    
private:
    void addLists(ListNode* l1, ListNode* l2, ListNode* prev, int carry) {
        
        // if both lists have been traversed, check if there is still a digit to carry over
        if (l1 == nullptr && l2 == nullptr) {
            
            if (carry == 0) { return; }
            
            ListNode* temp = new ListNode(carry);
            
            prev->next = temp;
            
            return;
        }
        
        int sum = 0, remainder = 0;
        
        ListNode* temp = new ListNode(0);
        
        prev->next = temp;
        
        // if either list has been fully traversed, add the remaining values and any digits that carry over
        if (l1 == nullptr) {
            
            sum = l2->val + carry;
            
            temp->val = sum % 10;
            
            addLists(nullptr, l2->next, temp, sum / 10);
            
            return;
        }
        
        if (l2 == nullptr) {
            
            sum = l1->val + carry;
            
            temp->val = sum % 10;
            
            addLists(l1->next, nullptr, temp, sum / 10);
            
            return;
        }
        
        // if neither list has been fully traversed, add and continue
        
        sum = l1->val + l2->val + carry;
            
        temp->val = sum % 10;
            
        addLists(l1->next, l2->next, temp, sum / 10);
            
        return;
    }
};