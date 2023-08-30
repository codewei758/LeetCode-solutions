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

    int numbers = 0;

    int goodNodes(TreeNode* root) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        dfs(root,root->val);
        return numbers;
    }

    int dfs(TreeNode* root,int max_num){
        if(!root) return 0;

        if(root->val >= max_num){
            ++numbers;
            max_num = root->val;
        }

        dfs(root->left,max_num);
        dfs(root->right,max_num);
        return 0;
    }
};

TEST(goodNodes_1448, goodNodes_1448_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.goodNodes_1448(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}