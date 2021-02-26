// 两个链表相交的问题

#include <iostream>
#include "list.h"

using namespace std;

Node* get_crossover_node(Node* head1, Node* head2) {
    Node* cur1 = head1;
    Node* cur2 = head2;

    while(cur1 != cur2) {
        cur1 = cur1 == NULL ? head2 : cur1->next;
        cur2 = cur2 == NULL ? head1 : cur2->next;
    }
    return cur1;
}

int main() {

}