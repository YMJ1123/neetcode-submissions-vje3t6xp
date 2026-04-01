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
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy; // tail 負責在後面串接新節點 先指向 dummy
        while (list1 != nullptr && list2 != nullptr) {
            ListNode* nextTemp1 = list1->next; //暫存下一站
            ListNode* nextTemp2 = list2->next; 
            if (list1->val < list2->val){
                tail->next = list1;
                list1 = nextTemp1;
            }
            else{
                tail->next = list2;
                list2 = nextTemp2;
            }

            tail = tail->next;
        }
        // 如果 list1 還有剩，整串接上去；如果 list2 還有剩，整串接上去
        if (list1 != nullptr) {
            tail->next = list1;
        } else if (list2 != nullptr) {
            tail->next = list2;
        }

        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 邊界條件：如果陣列是空的，直接回傳 nullptr
        if (lists.empty()) {
            return nullptr;
        }

        int step = 1; // 一開始的配對間距是 1 (0配1, 2配3...)
        
        // 當間距還小於總隊伍數時，比賽繼續！
        while (step < lists.size()) {
            
            // 遍歷所有隊伍，兩兩配對
            // 注意迴圈的遞增條件是 i += step * 2，因為每場比賽消耗兩支隊伍
            for (int i = 0; i + step < lists.size(); i += step * 2) {
                
                // 把 lists[i] 和 lists[i + step] 合併
                // 並且把贏家 (合併後的結果) 存回 lists[i]
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
                
            }
            
            // 每一輪結束後，晉級的隊伍間距會翻倍 (1 -> 2 -> 4 -> 8...)
            step *= 2; 
        }

        // 最後的總冠軍，一定會落在索引值 0 的位置
        return lists[0];
    }
};
