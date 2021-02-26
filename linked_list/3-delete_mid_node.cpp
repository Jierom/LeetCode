// 删除第 a/b 位置的节点


#include <iostream>
#include "list.h"

using namespace std;

Node* delete_ratio_node(Node* head, int a, int b) {
    if (a < 0 || a > b) {
        return head;
    }

    int n = 0;
    Node* cur = head;
    while (cur) {
        n++;
        cur = cur->next;
    }
    // 计算要删除的节点
    int m = (n * a) / b;
    if ((n * a) % b != 0) {
        m = m + 1;
    }
    cout << m << endl;

    // 删除节点
    Node* fakeNode = new Node(0);
    fakeNode->next = head;
    Node* pre = fakeNode;
    cur = head;
    while (--m && cur) {
        pre = pre->next;
        cur = cur->next;
    }
    pre->next = cur->next;
    return fakeNode->next;
}

int main() {
    // input
    List list({1,2,3,4,5,6});
    int a = 1;
    int b = 3;

    Node* res = delete_ratio_node(list.getListHead(), 5, 10);
    print_list(res);
    return 0;
}