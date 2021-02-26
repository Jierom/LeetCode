// 反转单向链表和双向链表

#include <iostream>
#include "list.h"

using namespace std;

Node* revert_list(Node* head) {
    Node* fakeHead = new Node(0);
    fakeHead->next = head;
    Node* pre = fakeHead;
    Node* cur = head;

    while(cur) {
        Node* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    head->next = nullptr;
    head = pre;
    return head;
}

int main() {
    List list({1,2,3,4,5,6,7});
    Node* res = revert_list(list.getListHead());
    print_list(res);
}
