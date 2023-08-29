#include "headers.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        int right_dep = 0;
        int left_dep = 0;
        if(root->left != nullptr){
            left_dep = maxDepth(root->left);
        }
        if(root->right != nullptr){
            right_dep = maxDepth(root->right);
        }

        return max(right_dep,left_dep)+1;
    }
};

TEST(maxDepth_104, maxDepth_104_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 1;
    EXPECT_EQ(s.maxDepth(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}