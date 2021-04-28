/*** 
 * @Author: gjwu
 * @Date: 2021-04-28 13:30:18
 * @Description: Medium - LRU 缓存机制
 * @Ref: https://leetcode-cn.com/problems/lru-cache/
 */

#include <iostream>
#include <map>

using namespace std;

class LRUCache {

struct ListNode {
    int k, v;
    ListNode* prev;
    ListNode* next;
    ListNode(int k, int v) : k(k), v(v), prev(NULL), next(NULL) {};
};

private:
    map<int, ListNode*> _table;
    ListNode* _head;
    ListNode* _tail;
    int _capacity;
    int _current_size = 0;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _head = new ListNode(-1, -1);
        _tail = _head;
    }

    void move_to_head(ListNode* node) {
        // 检查尾指针
        if (_tail == node && node->prev != _head) {
            _tail = node->prev;
        }
        // 从链表中拿出
        node->prev->next = node->next;
        if (node->next) {
            node->next->prev = node->prev;
        }
        // 插到头部
        node->next = _head->next;
        node->prev = _head;
        _head->next = node;
        if (node->next) {
            node->next->prev = node;
        }
    }

    void insert_to_head(ListNode* node) {
        // 检查并更新尾指针
        if (_tail == _head) {
            _tail = node;
        }
        // 插入到头部
        node->next = _head->next;
        node->prev = _head;
        _head->next = node;
        if (node->next) {
            node->next->prev = node;
        }
    }
    
    int get(int key) {
        map<int, ListNode*>::iterator iter = _table.find(key);
        if (iter == _table.end()) {
            return -1;
        }
        ListNode* node = iter->second;
        move_to_head(node);

        return node->v;
    }
    
    void put(int key, int value) {
        // 检查k是否存在
        map<int, ListNode*>::iterator iter = _table.find(key);
        if (iter != _table.end()) {
            ListNode* node = iter->second;
            node->v = value;
            move_to_head(node);
            return;   
        }

        // 构建新节点
        ListNode* node = new ListNode(key, value);
        // 检查容量,删除最后元素
        if (_current_size == _capacity) {
            ListNode* tmp = _tail;
            _tail = _tail->prev;
            _tail->next = tmp->next;
            _table.erase(tmp->k);
            delete tmp;
            _current_size--;
        }
        insert_to_head(node);

        // 更新哈希表
        _table.insert(pair<int, ListNode*>(key, node));
        _current_size++;
    }

    void print_list() {
        ListNode* cur = _head->next;
        while(cur) {
            cout << cur->k;
            cur = cur->next;
        }
        cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */