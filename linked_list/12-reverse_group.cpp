#include <iostream>
#include "list.h"

using namespace std;

void revert(Node* left, Node* start, Node* end, Node* right);

Node* reverseKGroup(Node* head, int k) {
    if (k < 2) {
        return head;
    }

    Node* left = nullptr;
    Node* start = nullptr;
    Node* cur = head;
    Node* end = nullptr;
    Node* right = nullptr;

    int cnt = 0;
    while(cur) {
        cnt++;
        right = cur->next;
        if(cnt == k) {
            start = left == nullptr ? head : left->next;
            end = cur;
            revert(left, start, end, right);
            head = left == nullptr ? cur : head;
            left = start;
            cnt = 0;
        }
        cur = right;
    }
    return head;
}

void revert(Node* left, Node* start, Node* end, Node* right) {
    Node* pre = left;
    Node* cur = start;
    while(cur != right) {
        Node* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    if (left != nullptr) {
        left->next = end;
    }
    start->next = right;
}

int main() {
    List list({1,2,3,4,5});
    Node* res = reverseKGroup(list.getListHead(), 2);
    print_list(res);
}