// 将链表按照某值划分成左边小，中间相等，右边大的形式

#include <iostream>
#include "list.h"

using namespace std;

Node* list_partition(Node* head, int k) {

    Node* smallHead = new Node(0);
    Node* equalHead = new Node(0);
    Node* bigHead = new Node(0);

    Node* cur = head;
    Node* smallCur = smallHead;
    Node* equalCur = equalHead;
    Node* bigCur = bigHead;
    while (cur) {
        Node* node = new Node(cur->val);
        if (cur->val < k) {
            smallCur->next = node;
            smallCur = smallCur->next;
        }
        else if (cur->val == k) {
            equalCur->next = node;
            equalCur = equalCur->next;
        }
        else {
            bigCur->next = node;
            bigCur = bigCur->next;
        }
        cur = cur->next;
    }

    cur = smallHead;
    while(cur->next) {
        cur = cur->next;
    }
    cur->next = equalHead->next;
    while(cur->next) {
        cur = cur->next;
    }
    cur->next = bigHead->next;
    return smallHead->next;
}

int main() {
    List list({9,0,4,5,1,3});

    Node* res = list_partition(list.getListHead(), 3);
    print_list(res);
}