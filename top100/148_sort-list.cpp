/*** 
 * @Author: gjwu
 * @Date: 2021-04-28 13:40:24
 * @Description: Medium - 排序链表
 * @Ref: https://leetcode-cn.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* node) {
        int len = 0;
        ListNode* cur = node;
        while(cur) {
            len++;
            cur = cur->next;
        } 
        if (len < 2) 
            return node;
        
        // find middle
        ListNode* a;
        ListNode* b;
        if (len == 2) {
            a = node;
            b = node->next;
            node->next = NULL;
        }
        else {
            ListNode* fast = node;
            ListNode* slow = node;
            while (fast && fast->next && slow) {
                fast = fast->next->next;
                slow = slow->next;
            }
            a = node;
            b = slow->next;
            slow->next = NULL;
        }
        a = mergeSort(a);
        b = mergeSort(b);
        return merge(a, b);
    }

    // guibing
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(a != NULL && b != NULL) {
            if (a->val <= b->val) {
                ListNode* node = new ListNode(a->val);
                cur->next = node;
                a = a->next;
                cur = cur->next;
            }
            else {
                ListNode* node = new ListNode(b->val);
                cur->next = node;
                b = b->next;
                cur = cur->next;
            }
        }
        while (a != NULL) {
            ListNode* node = new ListNode(a->val);
            cur->next = node;
            a = a->next;
            cur = cur->next;
        }
        while (b != NULL) {
            ListNode* node = new ListNode(b->val);
            cur->next = node;
            b = b->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};