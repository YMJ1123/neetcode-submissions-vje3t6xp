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
        ListNode* first = head;
        for (int i=0; i<n; i++){
            first = first->next;
        }

        // 特殊情況處理：如果要刪除的是頭節點 (例如 [1,2,3], n=3)
        // 此時 first 會跑到 nullptr
        if (first == nullptr) {
            return head->next;
        }

        ListNode* second = head;
        // ListNode* ans;
        while (first->next!=nullptr){
            first = first->next;
            // ans->next = second;
            second = second->next;
        }

        second->next = second->next->next;
        return head;
        
    }
};
