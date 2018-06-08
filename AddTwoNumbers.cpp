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
        ListNode* ans = new ListNode(0);
        ListNode* temp = new ListNode(0);
        int carry = 0;
        int l1Val = 0;
        int l2Val = 0;
        
        ans = temp;
        
        while(l1 || l2){
           
            if(l1){
                l1Val = l1->val;
                l1 = l1->next;
            }
            else{
                l1Val = 0;
            }
            
            if(l2){
                l2Val = l2->val;
                l2 = l2->next;
            }
            else{
                l2Val = 0;
            }
            
            temp->val = (((l1Val + l2Val) % 10) + carry) % 10;
            carry = (l1Val + l2Val + carry) / 10;
                        
            if(l1 || l2 || (carry > 0)){
                ListNode* next = new ListNode(carry);
                temp->next = next;
                temp = temp->next;
            }
        }
        
        return ans;
        
    }
};