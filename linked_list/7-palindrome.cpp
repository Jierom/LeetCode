// 判断一个链表是否回文

#include <iostream>
#include "list.h"

using namespace std;

Node* copy_list(Node* head) {
    Node* fakeHead = new Node(0);
    Node* copyCur = fakeHead;
    Node* cur = head;
    while(cur) {
        Node* node = new Node(cur->val);
        copyCur->next = node;
        copyCur = copyCur->next;
        cur = cur->next;
    }
    return fakeHead->next;
}

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

bool is_palindrome(Node* head) {
    // 先反转列表
    Node* copy_head = copy_list(head);
    Node* reverted_head = revert_list(head);

    Node* cur1 = copy_head;
    Node* cur2 = reverted_head;
    while(cur1 && cur2) {
        if (cur1->val != cur2->val) {
            break;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    if (cur1 == NULL && cur2 == NULL) {
        return true;
    }
    return false;
}

int main() {
    List list({1,2,3,3,2,1});
    bool res = is_palindrome(list.getListHead());
    cout << res << endl;
}