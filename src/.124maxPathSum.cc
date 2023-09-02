#include "headers.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;

        std::function<int(TreeNode*)> dfs = [&](TreeNode* node){
            if(!node){
                return 0;
            }

            int leftMax = dfs(node->left);
            int rightMax = dfs(node->right);
            leftMax = max(leftMax,0);
            rightMax = max(rightMax,0);

            res = max(res,node->val + leftMax + rightMax);
            return node->val + max(rightMax,leftMax);
        };
        dfs(root);
        return res;
    }
};

TEST(maxPathSum, maxPathSum_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.maxPathSum(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}