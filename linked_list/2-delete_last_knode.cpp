// 删除单链表和双链表倒数第k个节点

#include <iostream>
#include "list.h"

using namespace std;

// 删除单链表倒数第k个节点
Node* delete_single_last_knode(Node* head, int k) {
    Node* fakeHead = new Node(0);
    fakeHead->next = head;

    Node* pre = fakeHead;
    Node* cur = head;
    Node* fast = head;

    // 先让快指针走k步
    while(k-- && fast) {
        fast = fast->next;
    }
    if (fast == nullptr && k > 0) {
        return head;
    }
    // 同时走找到倒数k
    while(fast) {
        pre = pre->next;
        cur = cur->next;
        fast = fast->next;
    }
    // 删除节点
    pre->next = cur->next;
    return fakeHead->next;
}


// 删除双链表倒数第k个节点
DoubleNode* delete_double_last_knode(DoubleNode* head, int k) {
    DoubleNode* fakeHead = new DoubleNode(0);
    DoubleNode* pre = fakeHead;
    DoubleNode* cur = head;
    DoubleNode* fast = head;

    // 先让快指针走k步
    while(cur) {
        fast = fast->next;
    }
    if (fast == nullptr && k > 0) {
        return head;
    }
    // 同时走找到倒数k
    while(fast) {
        pre = pre->next;
        cur = cur->next;
        fast = fast->next;
    }
    // 删除节点
    pre->next = cur->next;
    cur->last = pre;
    if (cur->next != NULL) {
        DoubleNode* next = cur->next;
        next->last = cur;
    }
    return fakeHead->next;
}



int main() {
    List list({1,2,3,4,5});
    list.print();

    Node* res = delete_single_last_knode(list.getListHead(), 5);
    print_list(res);
}