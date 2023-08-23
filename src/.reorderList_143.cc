#include "headers.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> listDeq;
        ListNode* p = head->next;
        while(p!=nullptr){
            listDeq.push_back(p);
            p = p->next;
        }
        int flag = 1;
        p = head;
        while(!listDeq.empty()){
            if(flag){
                p->next = listDeq.back();
                listDeq.pop_back();
                flag = 0;
                p = p->next;
            }else{
                p->next = listDeq[0];
                listDeq.pop_front();
                flag = 1;
                p = p->next;
            }
        }
        p->next = nullptr;
    }
};

TEST(reorderList_143, reorderList_143_1)
{
    Solution s;
    List in = {1,2,3,4};
    List ans = {1,4,2,3};
    s.reorderList(in.head);
    EXPECT_TRUE(is_same_list(in.head,ans.head));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}