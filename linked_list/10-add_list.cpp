// 两个单链表生成相加链表

#include <iostream>
#include <stack>
#include "list.h"

using namespace std;

Node* add_list(Node* head1, Node* head2) {
    // 节点进栈
    stack<Node*> nodeStack1;
    stack<Node*> nodeStack2;

    Node* cur1 = head1;
    Node* cur2 = head2;
    while(cur1) {
        nodeStack1.push(cur1);
        cur1 = cur1->next;
    }
    while(cur2) {
        nodeStack2.push(cur2);
        cur2 = cur2->next;
    }

    // 处理相加
    stack<Node*> resStack;
    int ca = 0;
    while(!nodeStack1.empty() || !nodeStack2.empty()) {
        if (nodeStack1.empty()) {
            int num = (nodeStack2.top()->val + ca) % 10;
            Node* resNode = new Node(num);
            resStack.push(resNode);
            ca = (nodeStack2.top()->val + ca) / 10;
            nodeStack2.pop();
        }
        if (nodeStack2.empty()) {
            int num = (nodeStack1.top()->val + ca) % 10;
            Node* resNode = new Node(num);
            resStack.push(resNode);
            ca = (nodeStack1.top()->val + ca) / 10;
            nodeStack1.pop();
        }
        else {
            int num = (nodeStack1.top()->val + nodeStack2.top()->val + ca) % 10;
            Node* resNode = new Node(num);
            resStack.push(resNode);
            ca = (nodeStack1.top()->val + nodeStack2.top()->val + ca) / 10;
            nodeStack1.pop();
            nodeStack2.pop();
        }
    }
    if (ca != 0) {
        Node* resNode = new Node(ca);
        resStack.push(resNode);
        ca = 0;
    }
    
    // 构造结果链表
    Node* fakeHead = new Node(0);
    Node* cur = fakeHead;
    while(!resStack.empty()) {
        Node* resNode = resStack.top();
        cur->next = resNode;
        cur = cur->next;
        resStack.pop();
    }
    return fakeHead->next;
}

int main() {
    List list1({9,3,7});
    List list2({6,3});

    Node* res = add_list(list1.getListHead(), list2.getListHead());
    print_list(res);
}