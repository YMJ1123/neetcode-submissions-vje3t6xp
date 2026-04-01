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
    ListNode* reverseList(ListNode* head) {
        // 1. 初始化指針
        ListNode* prev = nullptr; // 前一個節點，一開始是空（因為反轉後頭變成尾） nullptr (走到盡頭)
        ListNode* curr = head;    // 當前節點
        while (curr != nullptr){
            ListNode* nextTemp = curr->next; //暫存下一站
            curr->next = prev; //反轉指針：將當前節點指向前一個

            //推進指針：大家一起往右移一步
            prev = curr;      // prev 變成現在的 curr
            curr = nextTemp;  // curr 變成原本的下一站
        }
        return prev; // 當迴圈結束時，curr 是 nullptr，而 prev 正好停在新的頭部
    }
};
