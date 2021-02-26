// 反转从 from 到 to 的节点

#include <iostream>
#include "list.h"

using namespace std;

Node* revert_part_node(Node* head, int from, int to) {

    // 判断输入
    int len = 0;
    Node* cur = head;
    while(cur) {
        len++;
        cur = cur->next;
    }
    if (from < 1 || to > len || from > to) {
        return head;
    }
    
    // 找到反转起始点
    Node* fakeHead = new Node(0);
    fakeHead->next = head;
    Node* pre = fakeHead;
    cur = head;
    int n = from;
    while(--n) {
        pre = pre->next;
        cur = cur->next;
    }
    Node* preFrom = pre;

    // 进行反转
    int gap = to - from + 1;
    while(gap--) {
        Node* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }

    // 最后调整
    preFrom->next->next = cur;
    preFrom->next = pre;
    return fakeHead->next;
}

int main() {
    List list({1,2,3,4,5,6});
    Node* res = revert_part_node(list.getListHead(), 2, 5);
    print_list(res);
}