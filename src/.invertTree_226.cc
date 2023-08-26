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
    TreeNode* invertTree(TreeNode* root) {
        ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
        if(root == nullptr){
            return nullptr;
        }

        if(root->left == nullptr && root->right == nullptr)
            return root;

        auto left = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);
        return root;
    }
};

TEST(invertTree_226, invertTree_226_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.invertTree_226(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}