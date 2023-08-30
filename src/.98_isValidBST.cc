#include "headers.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        return dfs(root,INT64_MIN,INT64_MAX);
    }

    bool dfs(TreeNode* node,long right,long left){
        if(!node) return true;

        if(!(node->val > right && node->val < left)) return false;

        return dfs(node->left,right,node->val) &&
               dfs(node->right,node->val,left);
    }

};

TEST(isValidBST, isValidBST_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.isValidBST(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}