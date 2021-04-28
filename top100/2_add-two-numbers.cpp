/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 14:53:03
 * @Description: Easy - 两数相加
 * @Ref: https://leetcode-cn.com/problems/add-two-numbers/
 */

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* root = new ListNode(0);
        ListNode* cursor = root;
        int carry = 0;

        while (l1 || l2 || carry != 0) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;

            ListNode* sumNode = new ListNode(sum % 10);
            cursor->next = sumNode;
            cursor = sumNode;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return root->next;
    }
};