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
 /*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *listchange = head;
        while (listchange != nullptr) {
            if (listchange->val == val) {
                ListNode *a = listchange->next; //(listchange->next)->next
                listchange = a;
            }
            if (listchange->next == nullptr) {
                break;
            }
            listchange = listchange->next;
        }
        return head;
    }
};
*/

// 方法1：分两次删除 头结点删除 非头结点删除
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // ListNode *lic = head;
        while (head != nullptr && head->val == val) {
            ListNode *tmp = head; //
            head = head->next;
            delete tmp; // 为了要把节点删除
        } // 可以确定第一个元素不等于val
        ListNode *lic = head;
        while (lic != nullptr && lic->next != nullptr) {    
            if (lic->next->val == val) {
                ListNode *tmp2 = lic->next; //
                lic->next = lic->next->next;//lic->|val|next|->|x|next|->|val|next|
                delete tmp2; // 为了要把节点删除
            } else {
                lic = lic->next;
            } 
        }
        // while (lic != nullptr) { //这个为什么不对呢，艹
        //     if (lic->val == val) {
        //         ListNode *tmp2 = lic; //
        //         lic = lic->next; //lic->|val|next|->|x|next|->|val|next|
        //         delete tmp2; // 为了要把节点删除
        //     } else {
        //         lic = lic->next;
        //     } 
        // }
        return head;
    }
};


// 方法2：设置头头节点删除 hhd->|0|head|->|val|next|->|x|next|->|val|next|
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* hhd = new ListNode(0); // hhd这个指针指向的是一个struct ListNode类
        hhd->next = head;
        while () {
            ListNode* mov = head;
            if (mov)
        }

        return head;
    }
};
