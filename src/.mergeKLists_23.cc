#include "headers.h"

class Solution {
public:
    struct op{
        bool operator()(ListNode* a,ListNode* b){
            return a->val>b->val;
        }
    };

    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

        if(lists.empty()) return nullptr;

        priority_queue<ListNode*,vector<ListNode*>,op> priorityQueue;
        for(auto head : lists){
            if(head!=nullptr)
                priorityQueue.push(head);
        }
        auto newHead = new ListNode(0);
        auto tail = newHead;
        while(!priorityQueue.empty()){
            auto node = priorityQueue.top();
            priorityQueue.pop();
            if(node->next != nullptr)
                priorityQueue.push(node->next);
            tail->next = node;
            tail = tail->next;
        }
        return newHead->next;
    }
};

TEST(mergeKLists_23, mergeKLists_23_1)
{
    Solution s;
    List in = {1,4,5};
    List in1 = {1,3,4};
    List in2 = {2,6};
    vector<ListNode*> lists = {in.head,in1.head,in2.head};

    List ans = {1,1,2,3,4,4,5,6};
//    EXPECT_EQ(s.mergeKLists(lists), ans);
    EXPECT_TRUE(is_same_list(s.mergeKLists(lists),ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}