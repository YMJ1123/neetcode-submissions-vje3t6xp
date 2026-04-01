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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        int addon = 0;
        int carry = 0;
        // while (first != nullptr){
        while (first != nullptr || second != nullptr || carry != 0) {
            // 取值：如果節點已經空了，就當作 0
            int x = (first != nullptr) ? first->val : 0;
            int y = (second != nullptr) ? second->val : 0;
            addon = x + y + carry;
            carry = 0;
            if (addon / 10 >=1){
                carry = addon/10;
                addon = addon%10;
            }
            curr->next = new ListNode(addon);
            curr = curr->next;
            // curr->val = addon;
            if(first != nullptr){
                first = first->next;
            }           
            if (second != nullptr){
                second = second->next;
            }
            
        }
        // if (carry != 0){
        //     curr= curr->next;
        //     curr->val = carry; 
        // }

        return ans->next;
    }
};
