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
class Solution { // 还是没有很懂
public:
    ListNode* reverseList(ListNode* head) { //题目里面给的都是不带头结点的
        ListNode* fastp = head;
        ListNode* slowp = nullptr;
        ListNode* temp;
        while (fastp) {
            temp = fastp->next; // temp向前走一格，这个最好还是放到循坏的开头，放到循环末尾会溢出
            fastp->next = slowp; // 交换
            slowp = fastp; // slowp向前走一格
            fastp = temp; // fast向前走一格
        } //我觉得这个妙处就在于处理好了开始的nullptr
        return slowp;
    }
};


// class Solution { // 还是没有很懂
// public:
//     ListNode* reverseList(ListNode* head) { //题目里面给的都是不带头结点的
//         ListNode* fap = head;
//         ListNode* slp = nullptr;
//         ListNode* temp;
//         while (fap) {
//             temp = fap->next;
//             fap->next = slp;
//             slp = fap;
//             fap = temp;
//         }
//         return slp;
//     }
// };
