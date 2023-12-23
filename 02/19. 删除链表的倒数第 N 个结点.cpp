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
// class Solution { // 不考虑删除不了吧，就是鲁棒性
// public: // 自己的方法
//     ListNode* removeNthFromEnd(ListNode* head, int n) {

//         ListNode* fastp = head;
//         int numb = 1;
//         while (fastp->next != nullptr) {
//             fastp = fastp->next;
//             numb ++;
//         }

//         ListNode* dummyHead = new ListNode(0);
//         dummyHead->next = head;
//         ListNode* slowp = dummyHead;
//         for (int i = 0; i < numb - n; i++) {
//             slowp = slowp->next;
//         }

//         ListNode* tmp = slowp->next;
//         slowp->next = slowp->next->next;
//         delete tmp;
//         return dummyHead->next;
        
//     }
// };

class Solution { // 艹，明明一开始想到用双指针的，快指针先走几步
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fastp = dummyHead;
        ListNode* slowp = dummyHead;

        for (int i = 0; i < n; i++) { //循环n次，背过
            fastp = fastp->next;
        }

        while (fastp->next != nullptr) {
            fastp = fastp->next;
            slowp = slowp->next;
        }

        ListNode* tmp = slowp->next;
        slowp->next = slowp->next->next;
        delete tmp;
        return dummyHead->next;
        
    }
};
