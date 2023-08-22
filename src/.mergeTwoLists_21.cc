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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto* head = new(ListNode);
        ListNode* back = head;
        ListNode* p = list1;
        ListNode* q = list2;
        while(p!=nullptr && q!=nullptr){
            if(q->val < p->val){
                back->next = q;
                q = q->next;
            }
            else{
                back->next = p;
                p = p->next;
            }
            back = back->next;
        }
        if(q!= nullptr) back->next = q;
        if(p!= nullptr) back->next = p;

        return  head->next;
    }
};

TEST(mergeTwoLists_21, mergeTwoLists_21_1)
{
    Solution s;
    vector<int> in = {1,2,4};
    vector<int> in2 = {1,3,4};
    vector<int> ans = {1,1,2,3,4,4};
    EXPECT_EQ(s.mergeTwoLists(s.createLists(in),s.createLists(in2), s.createLists(ans));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}