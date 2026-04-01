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
    // 輔助函式：從 curr 開始往後找第 k 個節點
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;
        while (true){
            //找出這組的第 k 個節點
            ListNode* kth = getKthNode(groupPrev, k);

            // 必定到最後會break
            if (kth == nullptr){
                break;
            }

            ListNode* groupNext = kth->next;

            // 開始反轉這k個
            // prev 不設為 nullptr，而是設為 groupNext，這樣尾巴就自動接好後面的路了
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            ListNode* oldHead = curr; // 這個 oldHead 反轉後會變成這組的尾巴，先記下來

            while (curr != groupNext){
                ListNode* nextTemp = curr->next; //暫存下一站
                curr->next = prev; //反轉指針：將當前節點指向前一個

                //推進指針：大家一起往右移一步
                prev = curr;      // prev 變成現在的 curr
                curr = nextTemp;  // curr 變成原本的下一站
            }
            // 將前一組的尾巴 (groupPrev) 接上剛剛反轉好的新頭部 (kth)
            groupPrev->next = kth;
            
            // 推進 groupPrev，讓它走到這組的尾巴 (也就是 oldHead)，準備下一回合
            groupPrev = oldHead;
        }
        return dummy->next;
    }
};
