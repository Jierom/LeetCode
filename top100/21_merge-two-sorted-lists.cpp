/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 14:58:35
 * @Description: Easy - 合并两个有序链表
 * @Ref: https://leetcode-cn.com/problems/merge-two-sorted-lists/
 */

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* cur1 = l1; 
        ListNode* cur2 = l2;

        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                ListNode* node = new ListNode(cur1->val);
                cur->next = node;
                cur = cur->next;
                cur1 = cur1->next;
            }
            else {
                ListNode* node = new ListNode(cur2->val);
                cur->next = node;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }
        while (cur1) {
            ListNode* node = new ListNode(cur1->val);
            cur->next = node;
            cur = cur->next;
            cur1 = cur1->next;
        }
        while (cur2) {
            ListNode* node = new ListNode(cur2->val);
            cur->next = node;
            cur = cur->next;
            cur2 = cur2->next;
        }

        return dummy->next;
    }
};