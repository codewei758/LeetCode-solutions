#include "headers.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){
            return true;
        }
        else if(p != nullptr &&  q != nullptr){
            if(p->val == q->val){
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            }
        }
        return false;
    }
};

TEST(isSameTree_100, isSameTree_100_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.isSameTree(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}