// 删除无序单链表中值重复出现的节点

#include <iostream>
#include "list.h"

using namespace std;

Node* delete_repeat_node(Node* head) {

    Node* cur = head;
    while(cur) {
        int val = cur->val;
        Node* p = cur;
        Node* q = cur->next;
        while(q) {
            if (q->val == val) {
                p->next = q->next;
                p = q;
                q = p->next;
            }
            else {
                p = p->next;
                q = q->next;
            }
        }
        cur = cur->next;
    }
    return head;
}

int main() {
    List list({1,4,3,1,4,5,3,2,5});
    Node* res = delete_repeat_node(list.getListHead());
    print_list(res);
}