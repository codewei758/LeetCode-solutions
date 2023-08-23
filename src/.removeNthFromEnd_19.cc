#include "headers.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre, *cur;
        pre = head;cur = head;
        int step = 0;
        while(step< n && cur!= nullptr)
        {
            cur = cur->next;
            step++;
        }
        if(step ==n && cur == nullptr)
        {
            head = head->next;
            delete pre;
            return head;
        }
        while(cur->next!=nullptr)
        {
            pre = pre->next;
            cur = cur->next;
        }
        ListNode* temp = pre->next;
        pre->next = temp->next;
        delete temp;
        return head;

    }
};

TEST(removeNthFromEnd_19, removeNthFromEnd_19_1)
{
    Solution s;
    List in = {1,2,3,4,5};
    List ans = {1,2,3,5};
    EXPECT_TRUE(is_same_list(s.removeNthFromEnd(in.head,2), ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}