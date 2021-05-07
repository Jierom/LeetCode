/*** 
 * @Author: gjwu
 * @Date: 2021-05-07 13:38:03
 * @Description: Medium - 两两交换链表中的节点
 * @Ref: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<iostream>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;

        while(cur) {
            if (!cur->next) {
                cur = cur->next;
                continue;
            }
            else if (!cur->next->next) {
                cur = cur->next->next;
                continue;
            }
            ListNode* p = cur->next;
            cur->next = p->next;
            p->next = cur->next->next;
            cur->next->next = p;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};