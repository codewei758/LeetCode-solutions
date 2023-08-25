#include "headers.h"

struct Node{
    Node* pre;
    Node* next;
    int key;
    int value;

    Node(int _key,int _value):key(_key),value(_value),pre(nullptr),next(nullptr){};
};

class LRUCache {
public:
    Node *head;
    Node *tail;
    unordered_map<int,Node*> unorderedMap;
    int cap;

    explicit LRUCache(int capacity) {
        unorderedMap.clear();
        cap = capacity;

        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->pre = head;
    }

    static void remove(Node* node){
        auto prev = node->pre;
        auto nxt = node->next;
        prev->next = nxt;
        nxt->pre = prev;
    }

    void insert(Node* node) const{
        auto prev = tail->pre;
        auto nxt = tail;
        prev->next = node;
        nxt->pre = node;
        node->next = nxt;
        node->pre = prev;
    }

    int get(int key) {
        if(unorderedMap.find(key)!=unorderedMap.end()){
            remove(unorderedMap[key]);
            insert(unorderedMap[key]);
            return unorderedMap[key]->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if(unorderedMap.find(key)!=unorderedMap.end()){
           unorderedMap[key]->value = value;
           remove(unorderedMap[key]);
           insert(unorderedMap[key]);
           return ;
        }else
        {
           unorderedMap[key] = new Node(key, value);
           insert(unorderedMap[key]);
        }

        if(unorderedMap.size() > cap){
            auto lru = head->next;
            remove(lru);
            unorderedMap.erase(lru->key);
            delete lru;
        }
    }
};

TEST(LRUCache_146, LRUCache_146_1)
{
    LRUCache s(2);
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.get(2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}