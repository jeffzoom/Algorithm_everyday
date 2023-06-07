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
// class Solution { // 就是说，节点的指向变换，值不变，要用虚拟头结点
// public:
//     ListNode* swapPairs(ListNode* head) {
        
//         ListNode* fakehead = new ListNode(0);
//         fakehead->next = head;

//         ListNode* fap = fakehead->next->next;
//         ListNode* slp = fakehead->next;
//         ListNode* temp = fakehead->next->next->next;

//         while (fakehead->next->next != nullptr && fakehead->next != nullptr) {
//             fap = fakehead->next->next;
//             slp = fakehead->next;
//             temp = fakehead->next->next->next;

//             fakehead->next = slp->next;
//             fap->next = slp;
//             slp->next = temp;

//             fakehead = fakehead->next->next;
//         }
//         return head;
//     }
// };
// fuck me 默写了一遍，翻转链表的加强版
// 就是说，节点的指向变换，值不变，要用虚拟头结点
class Solution { 
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* fakehead = new ListNode(0);
        fakehead->next = head; // 相当于重新创了一个节点 之前的head不要了
        ListNode* cur = fakehead;

        while (cur->next != nullptr && cur->next->next != nullptr) { // 错误2 这个范围不会写
            ListNode* tmp = cur->next;
            ListNode* tmp2 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp2;

            cur = cur->next->next; // 错误1，要有头结点，所以说next两次，不是三次
        }
        return fakehead->next;
    }
};