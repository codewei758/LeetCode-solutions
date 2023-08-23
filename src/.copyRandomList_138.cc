#include "headers.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }

    Node(int _val,Node* _random) {
        val = _val;
        next = nullptr;
        random = _random;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        for(Node* node = head;node!= nullptr;node = node->next->next){
            Node *nodenew = new Node(node->val);
            nodenew->next = node->next;
            node->next = nodenew;
        }

        for (Node* node = head; node != nullptr; node = node->next->next) {
            Node* nodeNew = node->next;
            nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }

        Node *headNew = head->next;
        for(Node* node = head; node != nullptr; node = node->next){
            Node* nodeNew = node->next;
            node->next = node->next->next;
            nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
        }
        return headNew;
    }
};

TEST(copyRandomList_138, copyRandomList_138_1)
{
    Solution s;
    auto d = new Node(0);
    auto head = d;
    d->random = d;
    d->next = new Node(1,d);
    d = d->next;
    d->next = new Node(2,head);
    s.copyRandomList(head);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}