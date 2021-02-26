// 环形约瑟夫问题，报数到3的自杀

#include <iostream>
#include "list.h"

using namespace std;

Node* round_josephus(Node* head) {    
    Node* fakeHead = new Node(0);
    fakeHead->next = head;
    Node* pre = fakeHead;
    Node* cur = head;

    int n = 1;
    while(cur != cur->next) {
        if (n % 3 == 0) {
            pre->next = cur->next;
            cur = cur->next;
        }
        else
        {
            pre = pre->next;
            cur = cur->next;
        }
        n++;
    }
    pre = nullptr;
    return cur;
}

int main() {
    // input
    List list({1,2,3,4,5});
    Node* cur = list.getListHead();
    while(cur->next) {
        cur = cur->next;
    }
    cur->next = list.getListHead();

    // resolve
    Node* res = round_josephus(list.getListHead());
    cout << res->val;
    res->next = nullptr;
    return 0;
}