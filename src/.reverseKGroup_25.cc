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
    ListNode* solve(ListNode* head,int k,int size){
        if(size < k){
            return head;
        }

        if(head == nullptr){
            return nullptr;
        }

        int i = 0;
        ListNode *curr = head, *nn = nullptr,*prev = nullptr;

        while(curr != nullptr && i<k){
            nn = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nn;
            i++;
        }

        head->next = solve(head->next,k,size-k);
        return prev;
    }

    int length(ListNode *head){
        int size_ = 0;
        auto ptr = head;
        while(ptr){
            ptr = ptr->next;
            size_++;
        }

        return size_;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = length(head);
        return solve(head,k,size);
    }
};

TEST(reverseKGroup_25, reverseKGroup_25_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.reverseKGroup_25(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}