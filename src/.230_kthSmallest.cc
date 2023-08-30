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
    int index = 0;
    int kthSmallest(TreeNode* root, int k) {
        ios::sync_with_stdio(false),cin.tie(nullptr), cout.tie(nullptr);
        return dfs(root,k);
    }

    int dfs(TreeNode* node, int k){
        if(!node){
            return -1;
        }
        int left = dfs(node->left,k);
        if(left!=-1) return left;
        index++;
        if(index == k) return node->val;
        int right = dfs(node->right,k);
        if(right != -1) return right;
        return -1;
    }
};

TEST(kthSmallest, kthSmallest_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.kthSmallest(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}