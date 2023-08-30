#include "headers.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto cur = root;
        while(cur){
            if(p->val > cur->val && q->val > cur->val){
                cur = cur->right;
            }else if(p->val < cur->val && q->val < cur->val){
                cur = cur->left;
            }else{
                return cur;
            }
        }
        return cur;
    }
};

TEST(lowestCommonAncestor_235, lowestCommonAncestor_235_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.lowestCommonAncestor(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}