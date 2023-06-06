/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution { //超出时间限制 fuck
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slowp = head;
//         ListNode* fastp = head;
//         while (slowp != nullptr) {
//             while (fastp != nullptr) {
//                 if (fastp->next == slowp) {
//                     return slowp;
//                 }
//             }
//             slowp = slowp->next;
//             fastp = slowp;
//         }
//         return nullptr;
//     }
// };

//fastp指针每次移动两个节点，slowp指针每次移动一个节点，
//如果 fastp 和 slowp指针在途中相遇 ，说明这个链表有环
class Solution { //超出时间限制 fuck
public:
    ListNode *detectCycle(ListNode *head) { //要么有环 要么没环 有环一定是在尾巴处
        ListNode* slowp = head;
        ListNode* fastp = head;
        //是否有环
        // while (fastp->next != nullptr && fastp->next->next != nullptr) {
        while (fastp != nullptr && fastp->next != nullptr) {
            slowp = slowp->next;
            fastp = fastp->next->next;
            if (fastp == slowp) { // 有环，找入口
                ListNode* fastNewp = slowp;
                ListNode* slowNewp = head;
                while (fastNewp != slowNewp) {
                    // fastNewp = fastNewp->next->next;
                    fastNewp = fastNewp->next;
                    slowNewp = slowNewp->next;
                }
                return fastNewp;
            }
        }
        return nullptr;
    }
};
