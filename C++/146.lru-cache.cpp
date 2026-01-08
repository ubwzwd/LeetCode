/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <unordered_map>
using namespace std;
// @lc code=start

struct BidirectionListNode {
    int val;
    int key;
    BidirectionListNode* next;
    BidirectionListNode* prev;
    BidirectionListNode(int x, int y) : val(y), key(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int size;
    int capacity;
    BidirectionListNode* head; // dummy node
    BidirectionListNode* tail; // dummy node
    unordered_map<int, BidirectionListNode*> queryMap;

    void addNodeToTail(BidirectionListNode* node) {
        BidirectionListNode* prev = tail->prev;
        node->next = tail;
        node->prev = prev;
        tail->prev = node;
        prev->next = node;
    }

    void removeNode(BidirectionListNode* node) {
        BidirectionListNode* prev = node->prev;
        BidirectionListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
        delete node;
    }

public:
    LRUCache(int capacity) : size(0), capacity(capacity), head(new BidirectionListNode(-1, -1)), tail(new BidirectionListNode(-1, -1)) {
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        BidirectionListNode* cur = head;
        while (cur != nullptr) {
            BidirectionListNode* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    
    int get(int key) {
        if (queryMap.count(key)) {
            // 1. get the key. 2. put the element in the linked list to the tail
            BidirectionListNode* node = queryMap[key];
            BidirectionListNode* prev = node->prev;
            BidirectionListNode* next = node->next;
            prev->next = next;
            next->prev = prev;
            addNodeToTail(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // check if existing
        if (get(key) >= 0) {
            queryMap[key]->val = value;
            return;
        }

        if (size < capacity) {
            size++;
        } else {
            // remove the head first
            BidirectionListNode* nodeToRemove = head->next;
            queryMap.erase(nodeToRemove->key);
            removeNode(nodeToRemove);
        }
        // put the item in the tail
        BidirectionListNode* node = new BidirectionListNode(key, value);
        addNodeToTail(node);
        queryMap[key] = node;
        return;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

