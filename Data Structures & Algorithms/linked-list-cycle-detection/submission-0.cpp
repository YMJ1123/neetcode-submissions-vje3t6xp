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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){// 關鍵條件：兔子(fast)還沒跑完，且兔子的下一步(fast->next)也不是終點
            slow = slow->next;       // 烏龜走一步
            fast = fast->next->next; // 兔子走兩步

            // check if meet
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};
