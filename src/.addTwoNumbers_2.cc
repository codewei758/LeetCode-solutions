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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newNode = new ListNode();
        ListNode* p = newNode;
        auto n1 = l1,n2 = l2;

        int flag = 0;

        while(n1||n2){
            int num1 = n1 ? n1->val:0;
            int num2 = n2 ? n2->val:0;
            p->next = new ListNode((num1+num2+flag)%10);
            flag = (num1+num2+flag)/10;

            p = p->next;

            if(n1) n1 = n1->next;
            if(n2) n2 = n2->next;
        }

        if(flag!=0){
            p->next = new ListNode(flag);
        }
        return newNode->next;
    }
};

TEST(addTwoNumbers_2, addTwoNumbers_2_1)
{
    Solution s;
    List in = {1, 2, 3};
    List in2 = {2,3,4};
    int ans = 1;
    EXPECT_EQ(s.addTwoNumbers(in.head,in2.head), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}