/*** 
 * @Author: gjwu
 * @Date: 2021-04-29 16:45:52
 * @Description: Medium - 删除链表的倒数第 N 个结点
 * @Ref: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        int k = n + 1;
        while (k-- && fast) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};