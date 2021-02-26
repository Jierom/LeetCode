#include <random>
#include <algorithm>
#include <iostream>

struct Node
{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

struct DoubleNode
{
    int val;
    DoubleNode* next;
    DoubleNode* last;
    DoubleNode(int v) : val(v), next(nullptr), last(nullptr) {}
};

void print_list(Node* head) {
    Node* cur = head;
    while(cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
};

class List
{
public:
    List()
    {
        root_ = nullptr;
    }
    List(const std::vector<int> &v) {
        getListFromVec(v);
    }
    Node *getListHead() {
        return root_;
    }
    void print() {
        Node *tmp = root_;
        while(tmp != nullptr) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }
    ~List() {
        while(root_ != nullptr) {
            Node *tmp = root_;
            root_ = root_->next;
            delete tmp;
        }
    }
private:
    Node *root_;

    void getListFromVec(const std::vector<int> &v) {
        if (v.size() == 0) {
            root_ = nullptr;
        }
        root_ = new Node(v[0]);
        Node *tmp = root_;
        for (int i = 1; i <= v.size() - 1; ++i) {
            Node *n = new Node(v[i]);
            tmp->next = n;
            tmp = n;
        }
    }
};

class DoubleList
{
public:
    DoubleList()
    {
        root_ = nullptr;
    }
    DoubleList(const std::vector<int> &v) {
        getListFromVec(v);
    }
    DoubleNode *getListHead() {
        return root_;
    }
    void print() {
        DoubleNode *tmp = root_;
        while(tmp != nullptr) {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }
    ~DoubleList() {
        while(root_ != nullptr) {
            DoubleNode *tmp = root_;
            root_ = root_->next;
            delete tmp;
        }
    }
private:
    DoubleNode *root_;

    void getListFromVec(const std::vector<int> &v) {
        if (v.size() == 0) {
            root_ = nullptr;
        }
        root_ = new DoubleNode(v[0]);
        DoubleNode *tmp = root_;
        for (int i = 1; i <= v.size() - 1; ++i) {
            DoubleNode *n = new DoubleNode(v[i]);
            tmp->next = n;
            tmp = n;
        }
    }
};