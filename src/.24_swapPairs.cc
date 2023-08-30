#include "headers.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        auto node = head->next;
        auto pre = head;

        auto newHead = new ListNode();
        newHead->next = head;
        auto tail = newHead;
        while(pre != nullptr){
            node = pre->next;
            if(node != nullptr){
                pre->next = node->next;
                node->next = pre;
                tail->next = node;
            }else
                tail->next = pre;
            tail = pre;
            pre = pre->next;

        }
        node = nullptr;
        pre = nullptr;
        delete node;
        delete pre;
        return newHead->next;
    }
};

TEST(swapPairs, swapPairs_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.swapPairs(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}