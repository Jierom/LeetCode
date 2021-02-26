// 两个有序列表的公共部分

#include<iostream>
#include "list.h"

using namespace std;

Node* findCommonPart(Node* head1, Node* head2) {
    Node* cur1 = head1;
    Node* cur2 = head2;
    while(cur1 && cur2) {
        if (cur1->val < cur2->val) {
            cur1 = cur1->next;
        }
        else if (cur1->val > cur2->val) {
            cur2 = cur2->next;
        }
        else {
            return cur1;
        }
    }
    return NULL;
}

int main() {
    List list1({1,2,4,7,9});
    List list2({3,4,7,9});

    Node* res = findCommonPart(list1.getListHead(), list2.getListHead());
    print_list(res);
    return 0;
}