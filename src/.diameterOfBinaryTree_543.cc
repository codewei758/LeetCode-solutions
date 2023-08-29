#include "headers.h"

class Solution {
public:

    int max_diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
       dfs(root);

       return max_diameter;
    }
    // pair : diameter and high
    int dfs(TreeNode* root){
        if(root == nullptr){
            return -1;
        }
        auto right = dfs(root->right);
        auto left = dfs(root->left);

        int diameter = right + left + 2;
        max_diameter = max(max_diameter,diameter);

        return  1 + max(right,left);

    }
};

TEST(diameterOfBinaryTree_543, diameterOfBinaryTree_543_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.diameterOfBinaryTree(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}