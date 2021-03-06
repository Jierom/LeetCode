/*** 
 * @Author: gjwu
 * @Date: 2021-04-27 15:11:46
 * @Description: Easy - 环形链表
 * @Ref: https://leetcode-cn.com/problems/linked-list-cycle/
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};