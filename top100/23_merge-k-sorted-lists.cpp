/*** 
 * @Author: gjwu
 * @Date: 2021-05-07 10:36:28
 * @Description: Hard - 合并K个升序链表
 * @Ref: https://leetcode-cn.com/problems/merge-k-sorted-lists/
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = devide(lists);
        return res;
    }

    ListNode* devide(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        int mid = lists.size() / 2;
        vector<ListNode*> list1;
        for (int i=0;i<mid;i++) {
            list1.push_back(lists[i]);
        }
        vector<ListNode*> list2;
        for (int i=mid;i<lists.size();i++) {
            list2.push_back(lists[i]);
        }
        ListNode* l1 = devide(list1);
        ListNode* l2 = devide(list2);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
            else {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }
        while (cur1) {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
        }
        while (cur2) {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
        }
        return dummy->next;
    }
};