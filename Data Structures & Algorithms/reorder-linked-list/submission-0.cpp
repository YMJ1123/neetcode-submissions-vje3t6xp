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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 條件：確保 fast 可以安全地走兩步
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 此時 slow 停在前半段的尾巴
        // 2. 切斷鏈結
        ListNode* secondHalfHead = slow->next; // 紀錄後半段的頭
        slow->next = nullptr;                  // 切斷！前半段現在獨立了

        // 反轉後半段
        ListNode* prev = nullptr; // 前一個節點，一開始是空（因為反轉後頭變成尾） nullptr (走到盡頭)
        ListNode* curr = secondHalfHead;    // 當前節點
        while (curr != nullptr){
            ListNode* nextTemp = curr->next; //暫存下一站
            curr->next = prev; //反轉指針：將當前節點指向前一個

            //推進指針：大家一起往右移一步
            prev = curr;      // prev 變成現在的 curr
            curr = nextTemp;  // curr 變成原本的下一站
        }
        ListNode* reversedSecondHalfHead = prev;

        // Merge 2 lists
        ListNode* first = head;                  // 前半段 (1->2->3)
        ListNode* second = reversedSecondHalfHead; // 後半段 (6->5->4)
        while (second != nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        } 

    }
};
