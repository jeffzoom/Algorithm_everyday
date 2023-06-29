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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numa = 0, numb = 0;
        ListNode *ca = headA, *cb = headB;
        while (ca != nullptr) {
            ca = ca->next;
            numa ++;
        }
        while (cb != nullptr) {
            cb = cb->next;
            numb ++;
        }

        ca = headA, cb = headB;
        if (numa > numb) {
            for (int i = 0; i < numa - numb; i++) {
                ca = ca->next;
            }
        } else if (numa < numb) {
            for (int i = 0; i < numb - numa; i++) {
                cb = cb->next;
            }
        }

        //要不要考虑鲁棒性啊，就是链表合上之后又分叉了
        // while (cb->next != ca->next && ca->next != nullptr) { //错误1：不可以这样，万一是
        //                         0 9 1 2 4
        //                             1 2 4
        //     ca = ca->next;
        //     cb = cb->next;
        // }
        // if (ca->next != nullptr) {
        //     return ca->next;
        // }
        // return nullptr;
        //
        while (cb != ca && ca != nullptr) {
            ca = ca->next;
            cb = cb->next;
        }
        if (ca != nullptr) {
            return ca;
        }
        return nullptr;

        // 代码随想录
        // while (ca != nullptr) { //好吧，这样写的话，确实不需要考虑链表合上之后又分叉了
        //     if (ca == cb) {
        //         return ca;
        //     }
        //     ca = ca->next;
        //     cb = cb->next;
        // }
        // return nullptr;
    }
};