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
};
